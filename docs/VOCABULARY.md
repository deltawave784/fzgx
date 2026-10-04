# Vocabulary

Names the librarian has fixed for the project, with the evidence behind them.
Owned types live in `include/`; generated module headers (`include/rel/<module>/`)
are never hand-edited.

## Types

Layout checks use `include/layout_check.h` (`CHECK_SIZE`, `CHECK_OFFSET`: array
typedefs, no code or data).

| Type | Header | Size | Evidence |
|------|--------|------|----------|
| `TRKBuffer`, `DSError`, `TRKEvent`, `TRKEventQueue`, `NubEventType` | `include/dolphin/trk.h` | 0x890 / - / 0xC / 0x28 | MetroTRK nub (msgbuf.c, nubevent.c); `TRKMSGBUF_SIZE` 0x880 data, three buffers at `lbl_801A36E8`. type-survey cluster of 12 views. |
| `OSContext`, `OSThread`, `OSMutex` (+ queue/link) | `include/dolphin/os/OSContext.h`, `OSThread.h` | 0x2C8 / 0x318 / 0x18 | Dolphin SDK OS. Six DOL units dropped local copies; `__OSUnlockAllMutex` now uses `queueMutex`/`link` instead of a padded view. The movie_module `fn_12_309D0`-family views at +0x168 (f64 pair) were mis-grouped by type-survey and are not OSContext. |
| `ADXTHandle` | `include/sofdec/adxt.h` | 0xC0 | CRI ADX talker handle (ADXT_Create/Stop/Pause/SetOutPan...); ten DOL units carried the identical definition plus a copy of `sofdec/sj.h`. Views in ADXT_DestroyAll and fn_8004DE70 remain local (padded union / partial view). |
