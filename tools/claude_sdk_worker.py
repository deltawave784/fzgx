#!/usr/bin/env python3
"""One matcher session through the Claude Agent SDK, for `orchestrate.py --harness claude`.

    python tools/claude_sdk_worker.py --model claude-opus-5-5 --system-prompt-file F --budget-usd 5 < prompt

Reads the task prompt on stdin and prints one JSON line shaped like `claude -p --output-format json`
(`result`, `total_cost_usd`, `num_turns`, `usage`, `modelUsage`), which `orchestrate.parse_claude` reads.
Sessions run `--bare`: the CLI authenticates only with ANTHROPIC_API_KEY (API credits), never the
subscription login, and loads no user/project settings, hooks or CLAUDE.md. Permission mode
`dontAsk` denies every tool outside --allowed-tools. When a terminal tool call writes
FZGX_RESULT_FILE the session is interrupted at once, and its final ResultMessage still reports the
cost, so the runner never has to kill a session (and count its whole cap) to stop it.
"""

from __future__ import annotations

import argparse
import asyncio
import json
import os
import sys
from pathlib import Path

from claude_agent_sdk import ClaudeAgentOptions, ClaudeSDKClient, ResultMessage


async def run(a: argparse.Namespace, prompt: str) -> dict:
    options = ClaudeAgentOptions(
        model=a.model,
        system_prompt={"type": "preset", "preset": "claude_code",
                       "append": Path(a.system_prompt_file).read_text(encoding="utf-8")},
        mcp_servers=a.mcp_config,
        allowed_tools=a.allowed_tools.split(","),
        permission_mode="dontAsk",
        max_budget_usd=a.budget_usd,
        setting_sources=[],
        cwd=a.cwd,
        extra_args={"bare": None, "strict-mcp-config": None, "disable-slash-commands": None,
                    "no-session-persistence": None},
    )
    out = {"result": "", "total_cost_usd": 0.0, "num_turns": None, "usage": {}, "modelUsage": {}}
    result_file = os.environ.get("FZGX_RESULT_FILE")

    async with ClaudeSDKClient(options=options) as client:
        async def stop_at_terminal():
            while not (result_file and os.path.exists(result_file)):
                await asyncio.sleep(0.5)
            out["interrupted"] = True
            await client.interrupt()

        watcher = asyncio.create_task(stop_at_terminal())
        try:
            await client.query(prompt)
            async for message in client.receive_response():
                if isinstance(message, ResultMessage):
                    out.update(result=message.result or "", total_cost_usd=message.total_cost_usd or 0.0,
                               num_turns=message.num_turns, usage=message.usage or {},
                               modelUsage=message.model_usage or {}, is_error=message.is_error,
                               subtype=message.subtype, api_error_status=message.api_error_status,
                               terminal_reason=message.terminal_reason)
        finally:
            watcher.cancel()
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--model", required=True)
    ap.add_argument("--system-prompt-file", required=True)
    ap.add_argument("--budget-usd", type=float, required=True)
    ap.add_argument("--mcp-config", default=".mcp.json")
    ap.add_argument("--allowed-tools", required=True)
    ap.add_argument("--cwd", default=".")
    a = ap.parse_args()
    out = asyncio.run(run(a, sys.stdin.read()))
    print(json.dumps(out), flush=True)
    return 1 if out.get("is_error") and not out.get("interrupted") else 0


if __name__ == "__main__":
    sys.exit(main())
