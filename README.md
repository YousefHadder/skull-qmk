# Skull QMK/Vial Firmware

Custom QMK/Vial keymap for the [Skull](https://mechboards.co.uk/) 34-key split keyboard by Gleb Sabirzyanov.

Ported from a Ferris Sweep ZMK configuration with home row mods, 5 layers, and eye RGB control.

## Features

- 🏠 Home row mods on top row (QWERTY)
- 🔢 5 layers: Base, Media/Nav, Numbers, Symbols, Right-hand mods
- 🔗 Combos for brackets/braces/parens (configured via Vial GUI)
- 👁️ Eye LED RGB control (toggle, hue, saturation, brightness)
- ⚡ Vial support for live keymap editing

## Prerequisites

This is a keyboard overlay repo — it needs vial-qmk as the base:

```bash
# Clone vial-qmk (one-time)
git clone -b vial https://github.com/vial-kb/vial-qmk.git ~/github/vial-qmk
cd ~/github/vial-qmk
make git-submodule

# Symlink this repo's keyboard into vial-qmk
ln -sf ~/github/skull-qmk/keyboards/skull ~/github/vial-qmk/keyboards/skull
```

## Build & Flash

```bash
cd ~/github/vial-qmk

# Build
make skull:yousef

# Build + flash (enter bootloader when prompted)
make skull:yousef:flash
```

## Entering Bootloader

- **Bootmagic reset**: Hold top-left key (Q) while plugging in USB
- **Physical reset button**: Press the button on the PCB
- **Keycode**: Press `QK_BOOT` if mapped

## Keymap

The keymap has 5 layers. Held thumb keys and a held `Z`/`;` switch layers; all other holds on the top row produce modifiers (home row mods). See [keyboards/skull/keymaps/yousef/keymap.c](keyboards/skull/keymaps/yousef/keymap.c) for the source.

Legend used below:
- `X/Mod` — tap for `X`, hold for `Mod` (home row mod)
- `X/Ln` — tap for `X`, hold to activate layer `n` (layer-tap)
- `Esc/Hyper` — tap `Esc`, hold for Hyper (`Ctrl+Shift+Alt+Cmd`)
- `Rct*` — Rectangle.app macOS window-management shortcut
- `___` — transparent (falls through to the base layer)
- `▓▓▓` — the key that activates this layer (held)

### Layer 0 — Base (QWERTY + home row mods)

```
┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
│Q/Alt│W/Sft│E/Ctl│R/Gui│  T  │       │  Y  │U/Gui│I/Ctl│O/Sft│P/Alt│
├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
│  A  │  S  │  D  │  F  │  G  │       │  H  │  J  │  K  │  L  │;/L4 │
├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
│Z/L1 │  X  │  C  │  V  │  B  │       │  N  │  M  │  ,  │  .  │  /  │
└─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
                  ┌─────┐                   ┌─────┐
                  │Bs/L2├─────┐       ┌─────┤Sp/L3│
                  └─────┤Esc/H│       │ Ent ├─────┘
                        └─────┘       └─────┘
```

- Top row letters double as home row mods on hold: `Q/W/E/R` → `Alt/Shift/Ctrl/Gui`, `U/I/O/P` → `Gui/Ctrl/Shift/Alt`. Tap behavior is unchanged.
- `Z` (tap) / Media-Nav layer (hold).
- `;` (tap) / Right-hand mods layer (hold).
- Left inner thumb: `Backspace` (tap) / Numbers layer (hold).
- Left outer thumb: `Esc` (tap) / Hyper = `Ctrl+Shift+Alt+Cmd` (hold).
- Right inner thumb: `Space` (tap) / Symbols layer (hold).
- Right outer thumb: `Enter`.
- Brackets, parens, and braces are reached via Vial-configured combos. Caps Lock is available through both a thumb-key combo and Layer 3.

### Layer 1 — Media / Navigation (hold `Z`)

```
┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
│Bri- │Bri+ │Prev │Play │Next │       │Vol- │Mute │Vol+ │     │  \  │
├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
│     │     │     │RctFL│     │       │ ←   │  ↓  │  ↑  │  →  │  '  │
├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
│▓▓▓▓▓│Shift│RctCE│     │     │       │RctLH│RctBH│RctTH│RctRH│  `  │
└─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
                  ┌─────┐                   ┌─────┐
                  │     ├─────┐       ┌─────┤RctMV│
                  └─────┤Space│       │RctEN├─────┘
                        └─────┘       └─────┘
```

- Top row, left hand: display brightness down/up, then media transport (Prev / Play-Pause / Next).
- Top row, right hand: volume down / mute / volume up, plus `\`.
- Home row, right hand: vim-style arrows on `H J K L`, with `'` on `;`.
- `RctFL` maximizes the focused window (Rectangle's fullscreen-without-spaces).
- Bottom row right hand: Rectangle halves — `LH` left, `BH` bottom, `TH` top, `RH` right — plus `` ` ``.
- `RctCE` centers the window. Bottom-left `Shift` is reachable while the layer is held.
- Right thumbs: `RctEN` (maximize) and `RctMV` (move window to next display). Left inner thumb produces a literal `Space` while the layer is held.

### Layer 2 — Numbers (hold left inner thumb / `Backspace`)

```
┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
│  1  │2/Sft│3/Ctl│4/Gui│  5  │       │  6  │7/Gui│8/Ctl│9/Sft│  0  │
├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
│  =  │  -  │  '  │Ctl+B│     │       │     │  ←  │  ↑  │  ↓  │  →  │
├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
│ MO1 │     │     │     │     │       │     │     │  ,  │  .  │     │
└─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
                  ┌─────┐                   ┌─────┐
                  │▓▓▓▓▓├─────┐       ┌─────┤RAlt │
                  └─────┤Space│       │ Ent ├─────┘
                        └─────┘       └─────┘
```

- Number row across the top with the same home-row-mod pattern as the base layer (`2/3/4` → `Shift/Ctrl/Gui`, `7/8/9` → `Gui/Ctrl/Shift`).
- Middle row left: math/punct cluster — `=`, `-`, `'`, plus `Ctrl+B` (tmux prefix).
- Middle row right: vim-style arrows on `J K L ;`. Hold either `Shift` home-row mod to select text, the right-thumb `Alt`/`Option` to move by word, or both to select by word.
- Bottom-left holds `MO(_MEDIA_NAV)` so you can chain into Layer 1 without releasing Backspace.
- Right hand keeps `,` and `.` in their home positions for numeric entry.
- Right outer thumb: `RAlt` (useful for Option-modified shortcuts while typing numbers).

### Layer 3 — Symbols (hold right inner thumb / `Space`)

```
┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
│  !  │  @  │  #  │  $  │  %  │       │  ^  │  &  │  *  │  (  │  -  │
├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
│Caps │     │  {  │  [  │  (  │       │  )  │  ]  │  }  │     │  =  │
├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │       │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
                  ┌─────┐                   ┌─────┐
                  │     ├─────┐       ┌─────┤▓▓▓▓▓│
                  └─────┤     │       │     ├─────┘
                        └─────┘       └─────┘
```

- Top row, left hand: shifted number row (`! @ # $ %`).
- Top row, right hand: `^ & * (` plus `-`.
- Middle row pairs openers and closers mirrored across the split so `{ [ (` on the left line up with `) ] }` on the right; `=` lives under `;`.
- `Caps Lock` is available on `A`.
- Bottom row is mostly empty — placeholder space if you want to add custom shortcuts.

### Layer 4 — Right-hand mods (hold `;`)

```
┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
│ Tab │     │     │     │     │       │     │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │       │     │ Cmd │ Ctl │Shift│▓▓▓▓▓│
├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │       │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
                  ┌─────┐                   ┌─────┐
                  │     ├─────┐       ┌─────┤     │
                  └─────┤     │       │     ├─────┘
                        └─────┘       └─────┘
```

- Provides plain (non-tap-hold) right-hand modifiers on `J K L` (`Cmd / Ctrl / Shift`) for cases where holding a home row mod would mis-fire.
- `Tab` is exposed in the top-left as a low-cost reach while the right thumb is busy.
- Everything else is transparent — pressing a base-layer key still types the base character.

### Eye RGB

The two eye sockets each have 3 LEDs synced across the split. Custom keycodes are exposed to Vial:

- `EY_TOGG` — toggle eyes on/off
- `EY_HUE` — step hue
- `EY_SAT` — step saturation
- `EY_VAL` — step value (brightness)

State is mirrored to the slave half via the `USER_SYNC_A` split RPC and persisted to EEPROM, so it survives reboots. Map these in the Vial GUI wherever you want them.

## Vial layout backup

The current Vial layout, combos, and dynamic settings are stored in
[`keyboards/skull/keymaps/yousef/skull-layout.vil`](keyboards/skull/keymaps/yousef/skull-layout.vil).
Use **File → Load Saved Layout** in Vial to restore it after flashing or resetting EEPROM.

## Hardware

- **MCU**: STM32F072
- **Bootloader**: stm32-dfu
- **Layout**: 34-key split (3×5 + 2 thumb keys per side)
- **RGB**: 26 LEDs (13 per half) + 3 eye LEDs per half
