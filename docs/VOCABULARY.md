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
