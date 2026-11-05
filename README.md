# ltsuda — QMK firmware for Keebio Iris CE Rev.1

External [QMK userspace](https://docs.qmk.fm/newbs_external_userspace) repository containing
the `ltsuda` keymap for the **Keebio Iris CE Rev.1**. This repo is designed to be used as
QMK's `user.overlay_dir`; you do **not** need to keep any of QMK's own tree in git here.

## What's in it

```
keyboards/keebio/iris_ce/rev1/keymaps/ltsuda/
    keymap.c     # the keymap (see below)
    rules.mk     # TRI_LAYER_ENABLE = yes
    config.h     # factory default RGB effect (ALPHAS_MODS)
qmk.json         # userspace build descriptor (qmk userspace-compile/targets)
```

The keyboard definition itself is stock upstream QMK — nothing from it is vendored here.

## Keyboard features (ltsuda)

Dual-OS keymap with runtime switching:

- **Boot → Windows.** Press the **top-right key** to toggle to **macOS** (and back).
  The toggle lives only on the two base layers; symbols/nav layers are OS-specific.
- **RGB colour indicator** — pixels show the active OS stack:
  - **blue** — Windows
  - **red** — macOS
  - **magenta** — Settings layer
  - Effect forced to `ALPHAS_MODS` (static two-tone, no motion); change freely in Settings —
    it reverts to ALPHAS_MODS at the next boot.
- **Layers**: Win base → Win symbols → Win nav · Mac base → Mac symbols → Mac nav ·
  Settings (hold **both** FN keys; release either to exit).
- Symbols/nav keys carry the matching OS modifier order; OS toggling is session-only.
- **OS toggle** = default-layer flip between macOS/Windows base layers (Esc unaffected).
  Backspace lives above {Space}; top-right key on base layers is the OS toggle only.

## Prerequisites

- QMK CLI installed and settings configured (`qmk doctor` must pass).
- QMK Firmware cloned once, e.g. via `qmk setup`.
- This repo cloned anywhere, e.g. `~/developer/keyboards`.

## Setup (once per machine)

```bash
cd ~/developer/keyboards
git pull                       # or clone the repo first
qmk config user.overlay_dir="$(realpath ~/developer/keyboards)"
```

## Build

Build everything listed in `qmk.json` (output lands in repo root):

```bash
cd ~/developer/keyboards
qmk userspace-compile
```

Or build just the one target (equivalent, output also copied to repo root):

```bash
qmk compile -kb keebio/iris_ce/rev1 -km ltsuda
```

## Flash

Keyboard must be connected as a USB HID device.

```bash
qmk flash -kb keebio/iris_ce/rev1 -km ltsuda
```

It will tell you to put the keyboard into bootloader mode — on the Iris CE rev1 this is:

- **double-tap** the physical Reset button (between the halves), or
- use the **QK_BOOT** key in the Settings layer (hold both FN keys → hit the
  **top-left** key).

The board appears as FLASH drive; the host (or QMK) copies the `.uf2` onto it
automatically. Flashing never touches EEPROM.

Manual flash (no QMK CLI needed): download `keebio_iris_ce_rev1_ltsuda.uf2`,
double-tap-reset, copy the `.uf2` to the drive, unplug/re-plug.

## Notes

- The keymap is **not** VIA-compatible by design (7 layers + custom keycodes).
- Build iterations: edit `keymap.c` → `qmk userspace-compile` → flash.
- `.gitignore` excludes `*.uf2` and other build artifacts — don't commit them.
