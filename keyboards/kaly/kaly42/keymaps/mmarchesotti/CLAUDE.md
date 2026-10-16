# Kaly42 — mmarchesotti keymap

Notes for building and flashing this keymap. Linux is the usual environment here; the
Windows sections below exist because the toolchain needs extra coaxing there.

## Building (Linux)

Nothing special — after `qmk setup` has installed the dependencies once:

    make kaly/kaly42:mmarchesotti
    make kaly/kaly42:mmarchesotti:flash

For flashing without root, install the udev rules this repo ships, which already tag
the STM32 DFU device (`0483:df11`) with `uaccess`:

    sudo cp util/udev/50-qmk.rules /etc/udev/rules.d/
    sudo udevadm control --reload-rules && sudo udevadm trigger

The bootmagic keys and the benign `firmware is corrupt` message described under
*Flashing* apply the same way.

## Building (Windows)

The `qmk` CLI and the ARM toolchain are not on the default Windows PATH, so a bare
`make kaly/kaly42:mmarchesotti` fails with `qmk: command not found` — QMK's Makefile
shells out to the CLI just to resolve the target. Build from the QMK MSYS shell
(installed at `C:\QMK_MSYS`):

    MSYSTEM=MINGW64 MSYS2_PATH_TYPE=inherit /c/QMK_MSYS/usr/bin/bash.exe -l -c \
      'export USERPROFILE="<your Windows profile path>"; \
       cd <repo> && make kaly/kaly42:mmarchesotti'

`USERPROFILE` must be exported *inside* the shell. MSYS2 strips it from the inherited
environment, and the mingw64 Python behind `qmk` resolves `Path.home()` from
`USERPROFILE` rather than `HOME`, so `find_qmk_userspace` otherwise dies with
`RuntimeError: Could not determine home directory`. Passing it as an env prefix does
not survive; the same traceback also appears harmlessly in the login banner, so ignore
it if the build reaches `[OK]`.

The ARM toolchain needs the git submodules initialized (`lib/chibios`,
`lib/chibios-contrib`) — `qmk setup` or `make git-submodule` handles that.

## Flashing (both platforms)

Split keyboard on a blackpill_f401 with the `stm32-dfu` bootloader. Each half has its
own controller and must be flashed separately with the same firmware.

Hold the half's bootmagic key while plugging **that half** into USB:

| Half  | Key         | Matrix  |
| ----- | ----------- | ------- |
| Left  | `Tab`       | `[0,0]` (QMK default) |
| Right | `Backspace` | `[4,5]` (set via `split.bootmagic` in `keyboard.json`) |

Then, calling the Windows exe directly (the MSYS login banner otherwise swamps the
output):

    /c/QMK_MSYS/opt/qmk/bin/dfu-util.exe -l
    /c/QMK_MSYS/opt/qmk/bin/dfu-util.exe -a 0 -d 0483:df11 \
      -s 0x08000000:leave -D kaly_kaly42_mmarchesotti.bin

On entry `dfu-util` reports `dfuERROR, status(10) = Device's firmware is corrupt`.
That is the normal STM32 bootloader status; dfu-util clears it and writes fine. A
successful write ends with `File downloaded successfully` and `Submitting leave
request`, after which `dfu-util -l` lists no devices.

## Keymap notes

`TAPPING_TERM` is lowered to 125ms in `config.h` for `RALT_T(KC_SPC)`, the only
tap-hold key in the keymap. The MapleStory layers use `SEND_STRING` chat macros, which
emit US-ANSI, matching the `S(KC_2)`-style symbols on `_LOWER`.
