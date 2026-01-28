// Copyright 2023 Kael Soares Augusto (@Dwctor)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum kaly_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _QWERTY,
  _RPGM
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case 0:
            if (pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
    }
}

enum combo_events {
  ADJUST_COMBO,
};

const uint16_t PROGMEM right_inner_thumb_combo[] = {LOWER, RAISE, COMBO_END};
combo_t key_combos[] = {
    [ADJUST_COMBO] = COMBO_ACTION(right_inner_thumb_combo),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ F │ P │ B │       │ J │ L │ U │ Y │Del│Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Esc│ A │ R │ S │ T │ G │       │ M │ N │ E │ I │ O │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Alt│ Z │ X │ C │ D │ V │       │ K │ H │ , │ . │ / │Ent│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Mod├───┐           ┌───┤Rai│
      *               └───┤Ctl├───┐   ┌───┤Low├───┘
      *                   └───┤Spc│   │Sft├───┘
      *                       └───┘   └───┘
      */
    [_BASE] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_DEL,  KC_BSPC,
        KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LALT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                    KC_LGUI, KC_LCTL, RALT_T(KC_SPC),   KC_LSFT, LOWER, RAISE
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Bsp│Del│ 3 │ 2 │ 1 │ ! │       │ & │ { │ } │ = │ @ │ ` │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │ \ │ 0 │ 6 │ 5 │ 4 │ * │       │ # │ ( │ ) │ : │ - │ | │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │ ^ │ $ │ 9 │ 8 │ 7 │ % │       │ + │ [ │ ] │ ; │ _ │ ~ │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [_LOWER] = LAYOUT_split_3x6_3(
        KC_BSPC, KC_DEL,  KC_3, KC_2, KC_1, S(KC_1),                    S(KC_7),   S(KC_LBRC), S(KC_RBRC), KC_EQL,     S(KC_2),    KC_GRV,
        KC_BSLS, KC_0,    KC_6, KC_5, KC_4, S(KC_8),                    S(KC_3),   S(KC_9),    S(KC_0),    S(KC_SCLN), KC_MINS,    S(KC_BSLS),
        S(KC_6), S(KC_4), KC_9, KC_8, KC_7, S(KC_5),                    S(KC_EQL), KC_LBRC,    KC_RBRC,    KC_SCLN,    S(KC_MINS), S(KC_GRV),
                                         _______, _______,  _______,    _______, _______,  _______
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┐
      * │Mut│F10│ F9│ F8│ F7│Sle│        │CUp│PgD│Up │PgU│CDe│CBs│
      * ├───┼───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┼───┤
      * │V+ │F11│ F6│ F5│ F4│Boo│        │Hom│Lft│Dwn│Rgt│End│Ins│
      * ├───┼───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┼───┤
      * │V- │F12│ F3│ F2│ F1│Res│        │CDn│CLf│CBs│CRt│Ent│PSn│
      * └───┴───┴───┴───┴───┴───┘        └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
     [_RAISE] = LAYOUT_split_3x6_3(
         KC_AUDIO_MUTE,     KC_F10, KC_F9, KC_F8, KC_F7, KC_SYSTEM_SLEEP,    C(KC_UP),   KC_PGDN,    KC_UP,      KC_PGUP,     C(KC_DEL), C(KC_BSPC),
         KC_AUDIO_VOL_UP,   KC_F11, KC_F6, KC_F5, KC_F4, QK_BOOTLOADER,      KC_HOME,    KC_LEFT,    KC_DOWN,    KC_RIGHT,    KC_END,    KC_INSERT,
         KC_AUDIO_VOL_DOWN, KC_F12, KC_F3, KC_F2, KC_F1, QK_REBOOT,          C(KC_DOWN), C(KC_LEFT), C(KC_BSPC), C(KC_RIGHT), KC_ENT,    KC_PRINT_SCREEN,
                                         _______, _______,  _______,    _______, _______,  _______
     ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┐
      * │GAM│MA2│M3 │Mup│M1 │MWU│        │ ' │Ent│PM1│ ^ │RM1│MPv│
      * ├───┼───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┼───┤
      * │RPG│MA1│MLf│MDn│MRg│MWD│        │ / │Tab│Esc│Tab│RST│MPy│
      * ├───┼───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┼───┤
      * │   │MA0│M6 │M5 │M2 │M4 │        │ ~ │Del│PM2│CTb│RM2│MNx│
      * └───┴───┴───┴───┴───┴───┘        └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
     [_ADJUST] = LAYOUT_split_3x6_3(
         TO(_QWERTY), KC_MS_ACCEL2, KC_MS_BTN3, KC_MS_UP,   KC_MS_BTN1,  KC_MS_WH_UP,              KC_GRV,    KC_ENT,  DM_PLY1, S(KC_6),    DM_REC1, KC_MPRV,
         TO(_RPGM),   KC_MS_ACCEL1, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN,            S(KC_BSLS), KC_TAB,  KC_ESC,  KC_TAB,    DM_RSTP, KC_MPLY,
         _______,     KC_MS_ACCEL0, KC_MS_BTN6, KC_MS_BTN5, KC_MS_BTN2,  KC_MS_BTN4,               S(KC_GRV),  KC_DEL,  DM_PLY2, C(KC_TAB), DM_REC2, KC_MNXT,
                                         _______, _______,  _______,    _______, _______,  _______
     ),
     /*
      * GAMING LAYER (QWERTY for WASD)
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│Bsp│ Q │ W │ E │ R │       │ T │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Esc│ ' │ A │ S │ D │ F │       │ G │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ / │ Z │ X │ C │ V │       │ B │ N │ M │ , │ . │Ent│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Alt├───┐           ┌───┤EXT│
      *               └───┤Ctl├───┐   ┌───┤   ├───┘
      *                   └───┤Spc│   │   ├───┘
      *                       └───┘   └───┘
      */
    [_QWERTY] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_BSPC,  KC_Q,    KC_W,    KC_E,    KC_R,              KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_ESC,  KC_QUOT,  KC_A,    KC_S,    KC_D,    KC_F,              KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_LSFT, KC_SLSH,  KC_Z,    KC_X,    KC_C,    KC_V,              KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_ENT,
                                           KC_LALT, KC_LCTL, KC_SPC,       _______, _______, TO(_BASE)
    ),
    /*
      * RPG MAKER GAMING LAYER (REPLACE WASD BY ARROWS)
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│Bsp│ Q │ ↑ │ E │ R │       │ T │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Esc│ W │ ← │ ↓ │ → │ F │       │ G │ H │ J │ K │ L │ / │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ S │ Z │ X │ C │ V │       │ B │ N │ M │ A │ D │Ent│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Alt├───┐           ┌───┤EXT│
      *               └───┤Ctl├───┐   ┌───┤   ├───┘
      *                   └───┤Spc│   │   ├───┘
      *                       └───┘   └───┘
      */
    [_RPGM] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_BSPC,  KC_Q,    KC_UP,   KC_E,        KC_R,              KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_ESC,  KC_W,     KC_LEFT, KC_DOWN, KC_RIGHT,    KC_F,              KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SLSH,
        KC_LSFT, KC_S,     KC_Z,    KC_X,    KC_C,        KC_V,              KC_B,    KC_N,    KC_M,    KC_A,    KC_D,    KC_ENT,
                                           KC_LALT, KC_LCTL, KC_SPC,       _______, _______, TO(_BASE)
    ),
};
