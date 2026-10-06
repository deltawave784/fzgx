"""SQLite work ledger: who owns which function, what it cost, what is blocked.

Lives in build/fzgx/ledger.db (gitignored). `snapshot()` writes the committed
state/ledger.json so history survives machines and sessions.
"""

from __future__ import annotations

import json
import sqlite3
import time
from pathlib import Path
from typing import Dict, Iterable, List, Optional

from .project import ROOT, STATE_DIR

SCHEMA = """
CREATE TABLE IF NOT EXISTS functions (
  symbol TEXT PRIMARY KEY, module TEXT, unit TEXT, addr INTEGER, size INTEGER,
  status TEXT CHECK(status IN ('unmatched','claimed','matched','blocked','seeded','asm')) DEFAULT 'unmatched',
  attempts INTEGER DEFAULT 0, best_percent REAL DEFAULT 0,
  claimed_by TEXT, claimed_at INTEGER, claim_ttl INTEGER,
  matched_commit TEXT, blocked_reason TEXT
);
CREATE TABLE IF NOT EXISTS attempts (
  id INTEGER PRIMARY KEY, symbol TEXT, agent TEXT, harness TEXT, model TEXT,
  started INTEGER, ended INTEGER, checks INTEGER DEFAULT 0, final_percent REAL,
  tokens_in INTEGER DEFAULT 0, tokens_out INTEGER DEFAULT 0, cost_usd REAL DEFAULT 0,
  outcome TEXT, notes TEXT, best_body_path TEXT
);
CREATE TABLE IF NOT EXISTS names (
  id INTEGER PRIMARY KEY, kind TEXT, target TEXT, proposed TEXT, rationale TEXT,
  proposed_by TEXT, status TEXT DEFAULT 'pending', applied_commit TEXT
);
CREATE TABLE IF NOT EXISTS batches (
  id TEXT PRIMARY KEY, started INTEGER, ended INTEGER, budget_usd REAL,
  spent_usd REAL DEFAULT 0, matched INTEGER DEFAULT 0, released INTEGER DEFAULT 0,
  blocked INTEGER DEFAULT 0
);
CREATE TABLE IF NOT EXISTS notes (
  id INTEGER PRIMARY KEY, symbol TEXT NOT NULL, kind TEXT NOT NULL, tu TEXT, detail TEXT NOT NULL,
  source TEXT, created_at INTEGER, status TEXT DEFAULT 'open', resolved_by TEXT, resolved_at INTEGER
);
CREATE INDEX IF NOT EXISTS idx_functions_status ON functions(status);
CREATE INDEX IF NOT EXISTS idx_attempts_symbol ON attempts(symbol);
CREATE INDEX IF NOT EXISTS idx_notes_symbol ON notes(symbol);
"""

# Structured matcher notes for the librarian: conflicts only a human/librarian can resolve.
NOTE_KINDS = ("prototype", "declaration", "data", "overlap", "hygiene", "naming", "other")
NOTE_MAX = 5          # notes per submit/release call
NOTE_CHARS = 300      # characters per note detail


class Ledger:
    def __init__(self, path: Optional[Path] = None) -> None:
        self.path = path or STATE_DIR / "ledger.db"
        self.path.parent.mkdir(parents=True, exist_ok=True)
        self.db = sqlite3.connect(self.path, timeout=30, isolation_level=None)
        self.db.row_factory = sqlite3.Row
        self.db.execute("PRAGMA journal_mode=WAL")
        self.db.execute("PRAGMA busy_timeout=30000")
        self.db.executescript(SCHEMA)
        cols = {r[1] for r in self.db.execute("PRAGMA table_info(attempts)")}
        for col, decl in (("stale_checks", "INTEGER DEFAULT 0"), ("best_in_attempt", "REAL DEFAULT 0"),
                          ("best_rows", "INTEGER")):
            if col not in cols:
                self.db.execute(f"ALTER TABLE attempts ADD COLUMN {col} {decl}")
        fcols = {r[1] for r in self.db.execute("PRAGMA table_info(functions)")}
        if "blocked_issue" in fcols:
            self.db.execute("ALTER TABLE functions DROP COLUMN blocked_issue")
        if "prev_status" not in fcols:
            # set while a shadow (A/B) claim is active; restored on finish
            self.db.execute("ALTER TABLE functions ADD COLUMN prev_status TEXT")
        if "link_state" not in fcols:
            # 'pending' = accepted on the object oracle, awaiting batch relink; 'verified' = hashes checked
            self.db.execute("ALTER TABLE functions ADD COLUMN link_state TEXT")
        sql = self.db.execute("select sql from sqlite_master where name='functions'").fetchone()[0]
        if "'asm'" not in sql:
            # 'asm' = links from its own assembly (no C can produce the body); widen the CHECK in place
            self.db.execute("PRAGMA writable_schema=ON")
            self.db.execute("UPDATE sqlite_master SET sql=replace(sql, \"'seeded')\", \"'seeded','asm')\") WHERE name='functions'")
            self.db.execute("PRAGMA writable_schema=OFF")
            self.db.close()
            self.db = sqlite3.connect(self.path, timeout=30, isolation_level=None)
            self.db.row_factory = sqlite3.Row
            self.db.execute("PRAGMA busy_timeout=30000")

    # ------------------------------------------------------------- inventory
    def sync_functions(self, rows: Iterable[dict]) -> int:
        """Insert unknown functions (status unmatched); never overwrite status."""
        n = 0
        with self.db:
            self.db.execute("BEGIN")
            for r in rows:
                cur = self.db.execute(
                    "INSERT OR IGNORE INTO functions(symbol,module,unit,addr,size) VALUES(?,?,?,?,?)",
                    (r["symbol"], r["module"], r.get("unit"), r["addr"], r["size"]),
                )
                n += cur.rowcount
                self.db.execute("UPDATE functions SET unit=?, size=? WHERE symbol=?",
                                (r.get("unit"), r["size"], r["symbol"]))
        return n

    def get(self, symbol: str) -> Optional[sqlite3.Row]:
        return self.db.execute("SELECT * FROM functions WHERE symbol=?", (symbol,)).fetchone()

    def list(self, module: Optional[str] = None, status: Optional[str] = None,
             limit: Optional[int] = None) -> List[sqlite3.Row]:
        q, args = "SELECT * FROM functions WHERE 1=1", []
        if module:
            q += " AND module=?"; args.append(module)
        if status:
            q += " AND status=?"; args.append(status)
        q += " ORDER BY module, addr"
        if limit:
            q += f" LIMIT {int(limit)}"
        return self.db.execute(q, args).fetchall()

    # ---------------------------------------------------------------- claims
    def expire_claims(self) -> int:
        now = int(time.time())
        with self.db:
            cur = self.db.execute(
                "UPDATE functions SET status=COALESCE(prev_status, 'unmatched'), prev_status=NULL, "
                "claimed_by=NULL, claimed_at=NULL, claim_ttl=NULL "
                "WHERE status='claimed' AND claimed_at + claim_ttl < ?", (now,))
        return cur.rowcount

    def claim(self, symbol: str, agent: str, ttl: int, max_attempts: int, shadow: bool = False) -> sqlite3.Row:
        """Claim for matching. A shadow claim (A/B runs) is allowed on matched functions,
        keeps the previous status to restore, and does not count toward the attempt cap."""
        self.expire_claims()
        with self.db:
            self.db.execute("BEGIN IMMEDIATE")
            row = self.get(symbol)
            if row is None:
                raise LookupError(f"{symbol}: not in ledger (run `fzgx sync`)")
            allowed = ("unmatched", "matched") if shadow else ("unmatched",)
            if row["status"] not in allowed:
                raise PermissionError(f"{symbol}: status is {row['status']}"
                                      + (f" (by {row['claimed_by']})" if row["claimed_by"] else ""))
            if not shadow and row["attempts"] >= max_attempts:
                raise PermissionError(f"{symbol}: attempt cap {max_attempts} reached; needs triage")
            self.db.execute(
                "UPDATE functions SET status='claimed', claimed_by=?, claimed_at=?, claim_ttl=?, prev_status=? WHERE symbol=?",
                (agent, int(time.time()), ttl, row["status"] if shadow else None, symbol))
            self.db.execute(
                "INSERT INTO attempts(symbol, agent, started) VALUES(?,?,?)",
                (symbol, agent, int(time.time())))
        return self.get(symbol)

    def current_attempt(self, symbol: str) -> Optional[sqlite3.Row]:
        return self.db.execute(
            "SELECT * FROM attempts WHERE symbol=? AND ended IS NULL ORDER BY id DESC LIMIT 1",
            (symbol,)).fetchone()

    def best_local_attempt(self, symbol: str) -> Optional[tuple]:
        """(attempt row, body path) of the best ended attempt whose saved body exists on this
        machine, ranked by best_in_attempt (the saved body is the attempt's best; final_percent
        is only its last check). A restored state/ledger.json carries the recording machine's
        absolute paths; a body copied into this checkout's .fzgx/attempts/ is found by name."""
        rows = self.db.execute(
            "SELECT * FROM attempts WHERE symbol=? AND ended IS NOT NULL AND best_body_path IS NOT NULL "
            "ORDER BY COALESCE(best_in_attempt, final_percent) DESC, id DESC", (symbol,)).fetchall()
        for row in rows:
            path = Path(row["best_body_path"])
            if not path.exists():
                path = STATE_DIR / "attempts" / path.name.replace("\\", "/").rsplit("/", 1)[-1]
            if path.exists():
                return row, path
        return None

    def bump_checks(self, symbol: str, percent: float, rows: Optional[int] = None) -> Dict[str, float]:
        """Record a check. Returns checks so far, consecutive non-improving checks, and bests.

        `percent` is one scale for the whole attempt (api.check_score: the better of objdiff's
        similarity and the pool-adjusted row score). `rows` is the count of instruction rows
        still differing after accepted pool/absolute relocations. Either a higher percent or
        fewer differing rows resets the plateau counter; only a higher percent replaces the
        attempt's best (`improved`, which also selects the saved best body)."""
        with self.db:
            att = self.current_attempt(symbol)
            improved = att is not None and percent > (att["best_in_attempt"] or 0.0)
            fewer = (att is not None and rows is not None
                     and (att["best_rows"] is None or rows < att["best_rows"]))
            self.db.execute(
                "UPDATE attempts SET checks=checks+1, final_percent=?, "
                "stale_checks=CASE WHEN ? THEN 0 ELSE stale_checks+1 END, "
                "best_rows=CASE WHEN ? THEN ? ELSE best_rows END, "
                "best_in_attempt=MAX(best_in_attempt, ?) WHERE symbol=? AND ended IS NULL",
                (percent, improved or fewer, fewer, rows, percent, symbol))
            self.db.execute(
                "UPDATE functions SET best_percent=MAX(best_percent, ?) WHERE symbol=?", (percent, symbol))
            att = self.current_attempt(symbol)
        return {"checks": att["checks"] if att else 0, "stale": att["stale_checks"] if att else 0,
                "best_in_attempt": att["best_in_attempt"] if att else percent, "improved": improved,
                "progress": bool(improved or fewer)}

    def finish(self, symbol: str, outcome: str, status: str, notes: str = "",
               commit: Optional[str] = None, body_path: Optional[str] = None,
               model: Optional[str] = None, harness: Optional[str] = None,
               tokens_in: int = 0, tokens_out: int = 0, cost_usd: float = 0.0,
               shadow: bool = False) -> None:
        if shadow:
            row = self.get(symbol)
            with self.db:
                self.db.execute(
                    "UPDATE attempts SET ended=?, outcome=?, notes=?, best_body_path=?, model=COALESCE(?,model), "
                    "harness=COALESCE(?,harness), tokens_in=tokens_in+?, tokens_out=tokens_out+?, cost_usd=cost_usd+? "
                    "WHERE symbol=? AND ended IS NULL",
                    (int(time.time()), "shadow-" + outcome, notes, body_path, model, harness, tokens_in, tokens_out,
                     cost_usd, symbol))
                self.db.execute(
                    "UPDATE functions SET status=?, claimed_by=NULL, claimed_at=NULL, claim_ttl=NULL, prev_status=NULL "
                    "WHERE symbol=?", ((row["prev_status"] if row else None) or "unmatched", symbol))
            return
        with self.db:
            self.db.execute(
                "UPDATE attempts SET ended=?, outcome=?, notes=?, best_body_path=?, model=COALESCE(?,model), "
                "harness=COALESCE(?,harness), tokens_in=tokens_in+?, tokens_out=tokens_out+?, cost_usd=cost_usd+? "
                "WHERE symbol=? AND ended IS NULL",
                (int(time.time()), outcome, notes, body_path, model, harness, tokens_in, tokens_out, cost_usd, symbol))
            self.db.execute(
                "UPDATE functions SET status=?, attempts=attempts+1, claimed_by=NULL, claimed_at=NULL, "
                "claim_ttl=NULL, matched_commit=COALESCE(?, matched_commit) WHERE symbol=?",
                (status, commit, symbol))

    def block(self, symbol: str, reason: str) -> None:
        with self.db:
            self.db.execute(
                "UPDATE functions SET status='blocked', blocked_reason=? WHERE symbol=?",
                (reason, symbol))

    def unblock(self, symbol: str) -> None:
        with self.db:
            self.db.execute(
                "UPDATE functions SET status='unmatched', blocked_reason=NULL, attempts=0 WHERE symbol=?",
                (symbol,))

    # ----------------------------------------------------------------- names
    def propose_names(self, symbol: str, agent: str, proposals: List[dict]) -> None:
        with self.db:
            for p in proposals:
                self.db.execute(
                    "INSERT INTO names(kind,target,proposed,rationale,proposed_by) VALUES(?,?,?,?,?)",
                    (p.get("kind", "function"), p.get("target", symbol), p["name"],
                     p.get("rationale", ""), agent))

    def pending_names(self) -> List[sqlite3.Row]:
        return self.db.execute("SELECT * FROM names WHERE status='pending' ORDER BY id").fetchall()

    # ----------------------------------------------------------------- notes
    def add_note(self, symbol: str, kind: str, detail: str, tu: Optional[str] = None,
                 source: Optional[str] = None) -> int:
        """Record one open note; an identical open note (symbol, kind, detail) is not duplicated."""
        if kind not in NOTE_KINDS:
            raise ValueError(f"note kind must be one of {', '.join(NOTE_KINDS)}")
        detail = " ".join(detail.split())[:NOTE_CHARS]
        if not symbol or not detail:
            raise ValueError("a note needs a symbol and a detail")
        with self.db:
            same = self.db.execute("SELECT id FROM notes WHERE symbol=? AND kind=? AND detail=? AND status='open'",
                                   (symbol, kind, detail)).fetchone()
            if same:
                return same["id"]
            return self.db.execute(
                "INSERT INTO notes(symbol, kind, tu, detail, source, created_at) VALUES(?,?,?,?,?,?)",
                (symbol, kind, tu or None, detail, source, int(time.time()))).lastrowid

    def notes(self, status: Optional[str] = None, symbol: Optional[str] = None,
              kind: Optional[str] = None) -> List[sqlite3.Row]:
        q, args = "SELECT * FROM notes WHERE 1=1", []
        for col, val in (("status", status), ("symbol", symbol), ("kind", kind)):
            if val:
                q += f" AND {col}=?"; args.append(val)
        return self.db.execute(q + " ORDER BY id", args).fetchall()

    def resolve_note(self, note_id: int, by: str = "librarian") -> bool:
        with self.db:
            return self.db.execute(
                "UPDATE notes SET status='resolved', resolved_by=?, resolved_at=? WHERE id=? AND status='open'",
                (by, int(time.time()), note_id)).rowcount == 1

    # ------------------------------------------------------------- reporting
    def summary(self) -> Dict[str, Dict[str, int]]:
        out: Dict[str, Dict[str, int]] = {}
        for r in self.db.execute(
                "SELECT module, status, COUNT(*) n, SUM(size) bytes FROM functions GROUP BY module, status"):
            out.setdefault(r["module"], {})[r["status"]] = r["n"]
            out[r["module"]][f"{r['status']}_bytes"] = r["bytes"] or 0
        return out

    def costs(self) -> sqlite3.Row:
        return self.db.execute(
            "SELECT COUNT(*) attempts, SUM(checks) checks, SUM(tokens_in) tokens_in, "
            "SUM(tokens_out) tokens_out, SUM(cost_usd) cost_usd FROM attempts").fetchone()

    def snapshot(self, path: Optional[Path] = None) -> Path:
        path = path or ROOT / "state" / "ledger.json"
        path.parent.mkdir(parents=True, exist_ok=True)
        data = {
            "generated": int(time.time()),
            "functions": [dict(r) for r in self.db.execute("SELECT * FROM functions ORDER BY module, addr")],
            "attempts": [dict(r) for r in self.db.execute("SELECT * FROM attempts ORDER BY id")],
            "names": [dict(r) for r in self.db.execute("SELECT * FROM names ORDER BY id")],
            "batches": [dict(r) for r in self.db.execute("SELECT * FROM batches ORDER BY started")],
            "notes": [dict(r) for r in self.db.execute("SELECT * FROM notes ORDER BY id")],
        }
        path.write_text(json.dumps(data, indent=1) + "\n")
        return path

    def restore(self, path: Optional[Path] = None) -> int:
        """Load a committed snapshot into an empty/new ledger (fresh clone or machine)."""
        path = path or ROOT / "state" / "ledger.json"
        if not path.exists():
            return 0
        data = json.loads(path.read_text())
        n = 0
        with self.db:
            self.db.execute("BEGIN")
            # "notes" is absent from snapshots older than 2026-10-06; .get() keeps them loadable
            for table in ("functions", "attempts", "names", "batches", "notes"):
                for row in data.get(table, []):
                    if table == 'functions':
                        row.pop('blocked_issue', None)  # snapshots from the retired issue workflow
                    cols = ",".join(row.keys())
                    qs = ",".join("?" * len(row))
                    n += self.db.execute(
                        f"INSERT OR REPLACE INTO {table}({cols}) VALUES({qs})", list(row.values())).rowcount
        return n
