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

See [keyboards/skull/keymaps/yousef/keymap.c](keyboards/skull/keymaps/yousef/keymap.c) for the full layout with ASCII art diagrams.

## Hardware

- **MCU**: STM32F072
- **Bootloader**: stm32-dfu
- **Layout**: 34-key split (3×5 + 2 thumb keys per side)
- **RGB**: 26 LEDs (13 per half) + 3 eye LEDs per half
