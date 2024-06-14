/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// To put this keyboard into bootloader mode, hold the top left key while the
// keyboard is unplugged, then plug it in when still holding it.

#include QMK_KEYBOARD_H

#define _SYMB      MO(_SYMBOL)
#define _NUMB      MO(_NUMBERS)
#define _EXCL      LSFT(KC_1)
#define _AT        LSFT(KC_2)
#define _HASH      LSFT(KC_3)
#define _DOLLAR    LSFT(KC_4)
#define _PERC      LSFT(KC_5)
#define _CAR       LSFT(KC_6)
#define _AMP       LSFT(KC_7)
#define _STAR      LSFT(KC_8)
#define _PIPE      LSFT(KC_BSLS)
#define _UNSC      LSFT(KC_MINS)
#define _PLUS      LSFT(KC_EQL)
#define _LPAR      LSFT(KC_9)
#define _RPAR      LSFT(KC_0)
#define _LCBR      LSFT(KC_LBRC)
#define _RCBR      LSFT(KC_RBRC)
#define _COLON     LSFT(KC_SCLN)

// Layer shorthand
enum layer_names {
    _BASE,
    _SYMBOL,
    _NUMBERS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer
     * .--------------------------------------------------------------.        .--------------------------------------------------------------.
     * | ~`     | 1      | 2      | 3      | 4      | 5      | -      |        | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     * | TAB    | Q      | W      | F      | P      | B      | [      |        | ]      | J      | L      | U      | Y      | ;:     | DEL    |
     * |--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     * | ESC    | A      | R      | S      | T      | G      | HOME   |        | PG UP  | M      | N      | E      | I      | O      | '"     |
     * |--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     * | LCTL   | Z      | X      | C      | D      | V      | END    |        | PG DN  | K      | H      | ,      | .      | /      | ENTER  |
     * '--------+--------+--------+--------+--------+-----------------+--------+-----------------+--------+--------+--------+--------+--------'
     *          | LGUI   | DEL    | SYMB   | LALT   | SPACE           |        | LSHIFT          | SYMB   | LGUI   |        | NUMB   |
     *          '--------------------------------------------------------------------------------------------------------------------'
     */
    [_BASE] = LAYOUT_classic(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,           KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_LBRC,           KC_RBRC, KC_J,	   KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL,
        KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_HOME,           KC_PGUP, KC_M,	   KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_END,            KC_PGDN, KC_K,	   KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                 KC_LGUI, KC_DEL,  _SYMB,   KC_LALT, KC_SPC,  KC_SPC,  _______,  KC_LSFT, KC_LSFT, _SYMB,   KC_LGUI, _______, _NUMB
    ),

    /* Symbol Layer
	 * .--------------------------------------------------------------.        .--------------------------------------------------------------.
     * |        | F1     | F2     | F3     | F4     | F5     | F11    |        | F12    | F6     | F7     | F8     | F9     | F10    | DEL    |
     * |--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        | !      | @      | #      |        |        |        | -      | [      | ]      | +      |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        | $      | %      | ^      |        |        |        | BACKSP | (      | )      | DEL    |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        | &      | *      | |      |        |        |        | _      | {      | }      | =      |        |        |
     * '--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------+--------+--------+--------'
     *          |        |        |        | :      | ENTER           |        |                 |        |        |        |        |
     *          '--------------------------------------------------------------------------------------------------------------------'
     */
    [_SYMBOL] = LAYOUT_classic(
        _______,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,           KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
        _______, _______, _______, _EXCL,   _AT,     _HASH,   _______,          _______, KC_MINS, KC_LBRC, KC_RBRC, _PLUS,   _______, _______,
        _______, _______, _______, _DOLLAR, _PERC,   _CAR,    _______,          _______, KC_BSPC, _LPAR,   _RPAR,   KC_DEL,  _______, _______,
        _______, _______, _______, _AMP,    _STAR,   _PIPE,   _______,          _______, _UNSC,   _LCBR,   _RCBR,   KC_EQL,  _______, _______,
                 _______, _______, _______, _COLON,  KC_ENT,  KC_ENT,  _______, _______, _______, _______, _______, _______, _______
    ),

    /* Number Layer
	 * .--------------------------------------------------------------.        .--------------------------------------------------------------.
     * | SLEEP  | F1     | F2     | F3     | F4     | F5     | F11    |        | F12    | F6     | F7     | F8     | F9     | F10    |        |
     * |--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------|
     * |        | 1      | 2      | 3      | 4      | 5      |        |        |        | 6      | 7      | 8      | 9      | 0      |        |
     * |--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        | 4      | 5      | 6      |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+        +--------+--------+--------+--------+--------+--------+--------|
     * | QK_BOOT|        |BL_TOGG | BRT+   | BRT-   |        |        |        |        |        | 1      | 2      | 3      |        | ENTER  |
     * '--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------+--------+--------+--------'
     *          | LGUI   | RGB_TOG| HUE+   | HUE-   |                 |        |                 | 0      | LGUI   |        |        |
     *          '--------------------------------------------------------------------------------------------------------------------'
     */
    [_NUMBERS] = LAYOUT_classic(
        KC_SLEP, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,           KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,          _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_4,    KC_5,    KC_6,    _______, _______,
        QK_BOOT, _______, BL_TOGG, RGB_VAI, RGB_VAD, _______, _______,          _______, _______, KC_1,    KC_2,    KC_3,    _______, KC_ENT,
                 KC_LGUI, RGB_TOG, RGB_HUI, RGB_HUD, _______, _______, _______, _______, _______, KC_0,    KC_LGUI, _______, _______
    )
};
