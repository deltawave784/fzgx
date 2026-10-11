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
| `PPCWGPipe` (= `WGPipe`), `GXWGFifo` | `include/dolphin/gx.h` | 0x8 | Dolphin SDK GX write-gather pipe at `GX_FIFO_BASE` as an MWCC absolute object; GXSetViewportJitter (fn_80038DE8) and GXSetFog (fn_800377F8) dropped their local copies byte-identically. Older units (fn_8003401C `__GXWGFifo`, fn_80034ECC/fn_80035110 `GXFIFO`, fn_80033D4C cast macro) keep theirs. |
| `__OSBusClock` (`OS_BUS_CLOCK`, `OS_TIMER_CLOCK`) | `include/dolphin/hw_regs.h` | 0x4 | Dolphin SDK low-memory bus clock (0x800000F8, address from ldscript.tpl). Same code as the literal `*(u32 *)0x800000F8` read in fn_800557CC, fn_80055EC0, fn_80022EA4. |
| `Obj_801A6C80_Target` (`lbl_801A6C80`) | `include/dol/globals.h` via `config/GFZE01/typedefs.json` | 0x5B28 | Pointee of the .sbss pointer `lbl_801A6C80`, set to `lbl_80193B48` by fn_80068BFC. Record arrays only (16x0x10 at 0, 15x0x10 at 0x48C, 64x0x20 voices at 0x588, map at 0xD88, 64x0x118 players at 0x1408); element fields still live in 18 units' private views (fn_80065390, fn_8005C5C8, fn_8005FCD8...). Name is the generator default, no retail evidence yet. |

Not promoted: padded-union views (`fields.view_<name>.<name>`) of `AdxBasicDecoder` in
fn_80043B48 and fn_80044A94 change code when rewritten as plain members (main.dol hash fails);
they stay local.

| `MwsPlayer` (extended) | `include/sofdec/mwsfd.h` | 0x204 | CRI MWSFD player handle (`mwPly*` error strings: "mwPlyLinkStm: handle is invalid"). +0x40 `sfd` (passed to SFD functions), +0x4C `lsc` (passed to LSC_Start / fn_80056xxx stream-controller calls), +0x54/+0x70/+0x71 still unnamed. Eleven fn_12_34xxx accessor units converted from `MovieModule` views. The +0xA8/+0x128 views (fn_12_35xxx `MovieModuleState`, fn_12_34390/34798) are not yet converted: their files carry several local helper types. |
