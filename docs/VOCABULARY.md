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
| `ARQRequest`, `ARQCallback` | `include/dolphin/ar.h` | 0x20 | Dolphin SDK ARQ (SDK field name `dest`); ARQPostRequest, __ARQInterruptServiceRoutine, __ARQServiceQueueLo, AXRNA units. |
| `AXPB` (+ sub-blocks), `AXVPB` | `include/dolphin/ax.h` | 0xF4 / 0x22C | Dolphin SDK AX voice parameter block as used by the AXRNA units and fn_8002123C. fn_8005A9B8 had a 0x140-byte `pb` view (pointer use only). |
| `AXRNAHandle` | `include/sofdec/axrna.h` | 0xE8 | CRI ADX AX renderer handle (AXRNA_Create/Finish/SetOutPan/ExecServer); six DOL units. |
| `AdxBasicDecoder`, `AdxXpnd`, `AdxXpndParams`, `AdxDecodeParams` | `include/sofdec/adxb.h` | 0xA0 / 0x3C / 0x14 / 0x2C | CRI ADX basic decoder (ADXB_ExecOne*) and ADPCM expander (ADXPD_*); nine DOL units. Padded-union views in ADXB_Create, fn_80042228, fn_80043B48, fn_80044A94 remain local. |
| `SJ`, `SJCK`, `SJInterface` | `include/sofdec/sj.h` (existing) | 0x4 / 0x8 / 0x30 | CRI stream joint; 22 more units (ADX DOL units, movie_module) now include it instead of identical copies. Variant views in fn_8004DE70 and fn_12_8F80/AE70/B3E0 remain local. |

Not promoted: padded-union views (`fields.view_<name>.<name>`) of `AdxBasicDecoder` in
fn_80043B48 and fn_80044A94 change code when rewritten as plain members (main.dol hash fails);
they stay local.
