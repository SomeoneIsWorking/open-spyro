# Prior art

Outside work on Spyro the Dragon (USA) `SCUS_942.28`, SHA-1 `84e3728ab94720d0873e2514adf4aade4935e0c5`, the build this tree matches. A reference names addresses; the psx-spyro
port's measurement decides behaviour. Address checks ran `decomp_pipeline.py --function-at` on our images
(2026-10-13); licences are GitHub SPDX ids; push dates checked 2026-11-13. Submodule pins named below are psx-spyro's
(2026-11-13, before this tree became its fork).

| project | URL | kind | license | target build | build match (addresses checked) | what we may take | notes |
|---|---|---|---|---|---|---|---|
| TheMobyCollective/spyro-1 | https://github.com/TheMobyCollective/spyro-1 | matching decomp (splat, gcc 2.7.2) | CC0-1.0 | Spyro 1 `SCUS_942.28` | matched: `sha256sum.txt` `PSX.EXE` equals our SHA-256 `a533d75c...`; `0x80022A2C`, `0x8004F000` present | code and names (CC0), copied with attribution | Submodule `external/spyro-1` pin `ccddb802`; upstream HEAD `8e1eabc1` (push 2026-11-08). `progress.md` marks all 270 listed functions matched. Builds 37 code overlays into `WAD.WAD`. |
| theMagicalKarp/open-spyro | https://github.com/theMagicalKarp/open-spyro | matching decomp | CC0-1.0 | Spyro 1 `SCUS_942.28` | matched: same SHA-1 (2026-08-12) | code and names (CC0), copied with attribution | Submodule `external/open-spyro` pin `a7be2b1d`; upstream HEAD `64177475` (push 2026-11-13). `PROGRESS.md` claims 100% of game code (2,106,332 bytes) matched, excluding 439 PSY-Q functions and 100 hand-written asm functions; the tree holds 533 `.c` and 115 `.s` files, consistent with the claim. Recent commits are readability passes. |
| alexbeavs-ps1-ports/spyro-the-dragon-recomp | https://github.com/alexbeavs-ps1-ports/spyro-the-dragon-recomp | static recompilation (psxrecomp) | PolyForm Noncommercial 1.0.0 (`LICENSE`; GitHub NOASSERTION) | Spyro 1 PAL `SCES-01438` (`game.toml`) | mismatched build: PAL | nothing | Last push 2026-11-11. |
| celophi/spyro-decompilation | https://github.com/celophi/spyro-decompilation | C reimplementation placed in extra RAM | none | Spyro 1 | not checked | nothing | Dormant since 2024-01. |
| abjeni/spyro-decompiler | https://github.com/abjeni/spyro-decompiler | whole-game MIPS-to-C decompiler with SDL3 host | GPL-3.0 | Spyro 1 (disc `.bin`, no hash stated) | not checked: no addresses or hash published | evidence only | Last push 2026-10-29. |
| FranklyGD/Spyro-Scope | https://github.com/FranklyGD/Spyro-Scope | live RAM and data viewer | GPL-3.0 | Spyro 1 NTSC-U, Spyro 2 NTSC, Spyro 3 NTSC v1.1 | not checked; Spyro 3 v1.1 is not our rev 0 | evidence only | Data-format reference; its terrain collision format (flag byte, water bit, slope) informs `docs/plans/more-vegetation.md`. |

Not found (2026-11-13): source for any Spyro 2 or 3 widescreen or 60 fps patch (the PCSX2-forum Spyro 3 widescreen
code targets NTSC-U v1.1, not our rev 0); a Spyro title on decomp.dev; a decomp of the sequels beyond the
TheMobyCollective splits. Searched GitHub repositories (titles, serials, "decomp", "recomp", "port", "widescreen",
"60fps"), decomp.dev and the web.

Not found (2026-11-12, for G006): any foliage, grass-density or vegetation mod for the PlayStation Spyro titles or
Reignited, or a grass-density enhancement in a decomp-based port of another title.

## How the port uses the two Spyro 1 decomps

Public reverse-engineering work on Spyro the Dragon. **Nothing is copied into this repo's own
sources** — these are pointers for cross-checking our RE (symbol names, function boundaries,
structure). Where a reference and our own measurement disagree, the measurement wins: this repo's
rule is that a claim cites evidence from the binary or a running port.

`open-spyro` is now a **submodule at `external/open-spyro`** (CC0), pinned to a commit so a checkout
is reproducible and the reference reaches subagents. It is a REFERENCE ONLY: never build it, never
copy its C into `game/`, and never let a symbol name stand in for evidence. What it is good for is
the two things that are expensive to derive from scratch and cheap to look up —

  * **Function boundaries and sizes.** `config/spyro.main.ld` carries `name = 0xADDR; // type:func
    size:0xN`. This settled C137 independently (0x80022A2C is 0x1098 = 1062 instructions, not the 598
    a lui-scan classifier had recorded) and confirmed four other sizes to within 20 instructions.
  * **Names, as a HYPOTHESIS to test.** They corrected the reading of C136 immediately — 0x8004F000 is
    `EmitStaticActorMeshListFogged`, so "never called in this capture" is a fogged-level variant, not
    a mystery. They also contradict part of the mute map (C138), which is what a reference is for:
    the disagreement is the finding, and the measurement decides it.

Its own progress notes are worth reading once: it excludes **92 hand-written assembly functions**
(~95 KB) as unmatchable from C because "they use `$at` as a data register" — that is exactly this
port's geometry-renderer family, and independent confirmation of the `$at`/`$ra`-as-data idiom that
caused the upstream `jr $ra` mis-classification in issue 0040.

`spyro-1` is a **submodule at `external/spyro-1`** (CC0), pinned to a commit like `open-spyro`. It is the
**primary decomp reference** for this repo — the most complete matching decompilation of SCUS_942.28 known
to this workspace (its README claims >40%; its own `progress.md` tracks all 270 listed functions (2026-11-13) as
matched, ~2.7x `open-spyro`'s figure). Verified 2026-08-16: its target `PSX.EXE` is SHA-1
`84e3728ab94720d0873e2514adf4aade4935e0c5`, **byte-identical to our extracted `SCUS_942.28`**, so its
`src/` names and `asm/nonmatchings/` hold OUR addresses with no translation. It has the same role as
`open-spyro` — a hypothesis source, never evidence — and covers more of the game.

## Decompilation projects

| project | what it is |
|---|---|
| [TheMobyCollective/spyro-1](https://github.com/TheMobyCollective/spyro-1) | **Primary decomp reference** (CC0, submodule at `external/spyro-1`). Matching decompilation of SCUS_942.28; 270/270 listed functions matched (2026-11-13). Same target checksum as our extraction, so `src/` names OUR addresses directly. |
| [theMagicalKarp/open-spyro](https://github.com/theMagicalKarp/open-spyro) | Byte-for-byte matching decompilation of SCUS_942.28 (CC0, submodule at `external/open-spyro`). Uses GCC 2.7.2 + maspsx + splat/spimdisasm; every commit rebuilds a byte-identical executable and stays runnable. Reports the game as the main EXE **plus 37 overlays**, ~828 functions (673 game, 155 PSY-Q/libc). Its `PROGRESS.md` claims 100% of game code C-matched (2026-11-13), excluding PSY-Q and 100 hand-written asm functions; our pin `a7be2b1d` predates that. Verified the same day: our extracted `SCUS_942.28` is SHA-1 `84e3728ab94720d0873e2514adf4aade4935e0c5`, **byte-identical to its target**, so `config/symbol_addrs.txt` and `include/{types,funcs,globals}.h` name OUR addresses with no translation. |
| [TheMobyCollective/spyro-2](https://github.com/TheMobyCollective/spyro-2) | Matching decompilation of SCUS_944.25 (CC0, submodule at `external/spyro-2`); `preparation/scus_944.25.yaml` sha1 equals our image. 102/330 EXE functions matched (2026-11-13). |
| [TheMobyCollective/spyro-3](https://github.com/TheMobyCollective/spyro-3) | Matching decompilation of SCUS_944.67 rev 0 (CC0, submodule at `external/spyro-3`); `preparation/scus_944.67.yaml` sha1 equals our image. 180/337 EXE functions matched (2026-11-13). |
| [celophi/spyro-decompilation](https://github.com/celophi/spyro-decompilation) | Decompilation to C using a different approach — recreated functions placed in extra RAM. |

## How these differ from this project

A **decompilation** recovers human-written source that recompiles to the original binary. This repo
is a native/Lightrec hybrid port: psxport dynamically translates instructions from the player's
authenticated executable and runtime WAD images, while measured native owners replace cohesive game
or platform behavior. The references remain useful for function boundaries and names to verify
against our own evidence, and for structural questions such as overlay ownership.

## Open cross-check

The overlay question is currently **unresolved**.
The decomp projects say 37 overlays exist; the disc image contains no per-overlay files. Runtime WAD
image activation and invalidation remain to be proven through Lightrec. This is exactly the kind of
discrepancy a reference is useful for surfacing and a running port is needed to settle.
