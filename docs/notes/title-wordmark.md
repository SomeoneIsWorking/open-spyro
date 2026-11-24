# Title wordmark

`WAD.WAD` entry 1 (directory word pair 1 at +0x08: offset 0x1B800, length 0x40000) is a 512 x 256-halfword block that
lands as VRAM (512, 256)..(1024, 512) byte for byte: VRAM row r is the entry's 0x400 bytes at +0x400 * (r - 256).

The title overlay draws the SPYRO THE DRAGON wordmark as sprite record 0 of its table at `0x8006FACC`: tpage `0x0098`
(8-bit, page (512, 256)), u 0, v 0, 255 x 128 texels, CLUT word `0x7FE0` (VRAM (512, 511), the block's last row,
256 entries). Colour 0 is transparent.
