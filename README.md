# cheapinoV2 Keyboard Configurations

My QMK firmware configurations for the cheapinoV2 split keyboard.

## Current Configuration

**Last Updated:** 2026-03-26

### Features

#### RGB LED
- **Startup Flash**: Cycles through colors on boot (2.5 second animation)
- **Layer Indication**: Built-in RP2040-Zero LED changes color per active layer

#### Keyboard Features
- **Home Row Mods**: LGUI/LALT/LCTL/LSFT on both hands (hold for modifier, tap for letter)
- **Mouse Keys**: Layer 2 — cursor movement, scroll wheel, buttons BTN1-3
- **Tap Dance**: Multi-tap keys (Q→Esc, Z, T, DOT, E)
- **Combos**: Adjacent key combos for arrow keys (right hand top row)
- **Encoder**: Volume up/down (base), prev/next track (layer 1), RGB mode (layer 3)
- **Caps Word**: Both shifts simultaneously activates Caps Word
- **NKRO**: Enabled

### Keymap Layers

- **Layer 0 (Base)**: Custom layout with home row mods (GACS both hands)
- **Layer 1 (Symbols)**: Punctuation, brackets, operators
- **Layer 2 (Mouse/Nav)**: Mouse cursor, scroll, arrow keys, clipboard shortcuts
- **Layer 3 (Numpad/Fn)**: Numpad, F1–F12 keys
- **Layer 7**: Alternative base layout

### Layer LED Colors

| Layer | Color |
|-------|-------|
| 0 (Base) | Red |
| 1 | Blue |
| 2 | Cyan |
| 3 | Green |
| 4 | Green (85) |
| 5 | Yellow |
| 6 | Purple |

## Directory Structure

```
cheapinoV2/
├── README.md                               # This file
├── keyboards/cheapino/
│   ├── keyboard.json                       # Pin mapping, layout, USB descriptor
│   ├── config.h                            # Tapping term, RGB, WS2812 settings
│   ├── rules.mk                            # Build options
│   ├── cheapino.c                          # RGB flash + layer color logic
│   ├── encoder.c/h                         # Encoder click/turn actions per layer
│   ├── matrix.c                            # Custom matrix scan (diodeless design)
│   ├── ghosting.c/h                        # Ghost key suppression
│   ├── halconf.h / mcuconf.h               # RP2040 HAL overrides
│   └── keymaps/default/
│       └── keymap.json                     # QMK Configurator keymap (default)
└── vial/
    └── cheapino.json                       # Vial export (personal layout)
```

## Flashing Firmware

### Setup QMK (one-time)

```bash
# Inside qmk_firmware folder:
git remote add tompi https://github.com/tompi/qmk_firmware
git fetch tompi cheapinov2
git checkout tompi/cheapinov2
```

### Compile & Flash

```bash
qmk flash -kb cheapino -km default
# or for a custom keymap:
qmk flash -kb cheapino -km <keymap_name>
```

When QMK says "Waiting for drive to deploy", hold **BOOT** and press **RESET** on the RP2040-Zero to enter DFU mode.

### Vial (GUI, no compile needed)

1. Flash `cheapino_vial.uf2` from the [releases page](https://github.com/tompi/cheapino/releases)
2. Open [vial.rocks](https://vial.rocks) or the [Vial desktop app](https://get.vial.today/download/)
3. Load `vial/cheapino.json` via **File → Load saved layout**

## Configuration Details

### Build Options (`rules.mk`)
- **Custom Matrix**: Enabled (`lite` mode) — diodeless design requires special scan
- **RGB Light**: WS2812 via RP2040 PIO1
- **Caps Word**: Enabled
- **Deferred Execution**: Enabled (used for startup LED animation)
- **Ghosting Fix**: Custom software ghost suppression in `ghosting.c`

### Encoder Actions (`encoder.c`)

| Layer | Clockwise | Counter-Clockwise | Click |
|-------|-----------|-------------------|-------|
| Base  | Page Down | Page Up           | Play/Pause |
| 3     | Ctrl+Tab  | Ctrl+Shift+Tab    | Play/Pause |
| 5     | GUI+Y     | GUI+Z             | Play/Pause |
| 6     | Vol Up    | Vol Down          | Play/Pause |

## Changelog

### 2026-03-26 - Initial Repository Setup
- Added all QMK keyboard source files from tompi/cheapinov2 branch
- Enabled LED layer indication in `cheapino.c`
- Added personal Vial layout export (`vial/cheapino.json`)
- Added default QMK keymap (`keyboards/cheapino/keymaps/default/keymap.json`)
