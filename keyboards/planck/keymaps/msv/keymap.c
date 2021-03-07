/* Copyright 2015-2017 Jack Humbert
 *
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

#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST,
  _FN,
  _SPACE_FN
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN MO(_FN)
#define SPACE_FN LT(_SPACE_FN, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
  * ,-----------------------------------------------------------------------------------------------.
  * | Tab       |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp       |
  * |-----------+------+------+------+------+------+------+------+------+------+------|------------|
  * | (LCTL)Esc |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | RCMD(Enter)|
  * |-----------+------+------+------+------+------+------+------+------+------+------+------------|
  * | Shift     |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  RSFT(")   |
  * |-----------+------+------+------+------+------+------+------+------+------+------+------------|
  * | Ctrl      |   FN | Alt  | GUI  |Lower | Space Layer |Raise | Left | Down |  Up  |  Right     |
  * `----------------------------------------------------------------------------------+------------'
  */
  [_QWERTY] = LAYOUT_planck_grid(
      KC_TAB,          KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,     KC_Y,     KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
      LCTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,     KC_H,     KC_J,   KC_K,    KC_L,    KC_SCLN, RCMD_T(KC_ENT),
      KC_LSFT,         KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,     KC_N,     KC_M,   KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_QUOT) ,
      KC_LCTL,         FN,      KC_LALT, KC_LGUI, LOWER,  SPACE_FN, SPACE_FN, RAISE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  /* Lower
  * ,-----------------------------------------------------------------------------------.
  * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |      |      |      |      |   *  |   4  |   5  |   6  |   -  |Enter |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |      |      |   /  |   1  |   2  |   3  |   +  |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |    Space    |      |   0  |   .  |   =  |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_LOWER] = LAYOUT_planck_grid(
      XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,     KC_8,    KC_9,     KC_0,     KC_BSPC, 
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ASTR,  KC_4,     KC_5,    KC_6,     KC_MINS,  MT(MOD_LSFT, KC_ENT), 
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH,  KC_1,     KC_2,    KC_3,     KC_PLUS,  XXXXXXX, 
      _______, XXXXXXX, _______, _______, _______, KC_SPC,  KC_SPC,   _______,  KC_0,    KC_DOT,   KC_EQL,   XXXXXXX
  ),

  /* Raise
  * ,-----------------------------------------------------------------------------------.
  * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  | PgDn | PgUp | Bksp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |   `  |   +  |   /  |   {  |   [  |   ]  |   }  |   \  |   -  |   =  | Enter|
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |   (  |      |      |   )  |      |   _  |   +  |   |  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |    Space    |      | Home |      |      | End  |            
  * `-----------------------------------------------------------------------------------'
  */
  [_RAISE] = LAYOUT_planck_grid(
      KC_TILD,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR, KC_ASTR, KC_PGDN, KC_PGUP, KC_BSPC, 
      XXXXXXX,  KC_GRV,  KC_PLUS, KC_SLSH, KC_LCBR,  KC_LBRC,  KC_RBRC,  KC_RCBR, KC_BSLS, KC_MINS, KC_EQL,  MT(MOD_LSFT, KC_ENT), 
      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN,  XXXXXXX,  XXXXXXX,  KC_RPRN, XXXXXXX, KC_UNDS, KC_PLUS, KC_PIPE, 
      _______,  XXXXXXX, _______, _______, _______,  KC_SPC,   KC_SPC,   _______, KC_HOME, XXXXXXX, XXXXXXX, KC_END
  ),

  /* Fn
  * ,-----------------------------------------------------------------------------------.
  * |DelWrd|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | Del  |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |  F11 |  F12 |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      | BriDn| BriUp|      |      | MUTE |VOLDWN|VOL UP|      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |    Space    |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_FN] = LAYOUT_planck_grid(
      LALT(KC_BSPC),  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,       KC_F9,     KC_F10,  KC_DEL, 
      XXXXXXX,        KC_F11,  KC_F12,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,   XXXXXXX, XXXXXXX, 
      XXXXXXX,        XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU,  XXXXXXX,  XXXXXXX,  KC__MUTE, KC__VOLDOWN, KC__VOLUP, XXXXXXX, XXXXXXX, 
      _______,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_SPC,   KC_SPC,   XXXXXXX,  XXXXXXX,     XXXXXXX,   XXXXXXX, XXXXXXX
  ),


  /* Space fn
  * ,-----------------------------------------------------------------------------------.
  * |PRNT SC|      |  UP  |      |      |      |      |      |      |      |      |     |
  * |-------+------+------+------+------+-------------+------+------+------+------+-----|
  * |       | LEFT | DOWN | RIGHT|      |      |      | LEFT | DOWN |  UP  | RIGHT|     |
  * |-------+------+------+------+------+------|------+------+------+------+------+-----| 
  * |       |      |      |      |      |      |      |      |      |      |      |     |
  * |-------+------+------+------+------+------+------+------+------+------+------+-----|
  * |       |      |      |      |      |             |      | MUTE |VOLDWN|VOL UP|     |
  * `-----------------------------------------------------------------------------------'
  */
  [_SPACE_FN] = LAYOUT_planck_grid(
      KC_PSCR,  XXXXXXX, KC_UP,    XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX,    XXXXXXX, 
      XXXXXXX,  KC_LEFT, KC_DOWN,  KC_RIGHT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LEFT, KC_DOWN,  KC_UP,       KC_RIGHT,   XXXXXXX, 
      XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX,    XXXXXXX, 
      XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,  _______,  _______,  XXXXXXX, KC__MUTE, KC__VOLDOWN, KC__VOLUP,  XXXXXXX
  ),

  /* Adjust (Lower + Raise)
  * ,------------------------------------------------------------------------------------.
  * | Reset|Qwerty|      |      |      |       |      |      | RGB  |RGBMOD|MIDIof|MIDIon| 
  * |------+------+------+------+------+--------------+------+------+------+------+------|
  * | Debug|      |      |Dvorak|      |AGnorm |AGswap|      | HUE- | HUE+ |Audoff|Aud on|
  * |------+------+------+------+------+-------|------+------+------+------+------+------|
  * |      |      |      |Colemk|      |TermOff|TermOn|      | SAT- | SAT+ |Musoff|Mus on|
  * |------+------+------+------+------+-------+------+------+------+------+------+------|
  * |Plover|      |      |      |      |              |      |BRGTH-|BRGTH+|Voice-|Voice+|
  * `-----------------------------------------------------------------------------------'
  */
  [_ADJUST] = LAYOUT_planck_grid(
      RESET,   QWERTY,  XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_MOD, MI_OFF, MI_ON,
      DEBUG,   XXXXXXX, XXXXXXX,   DVORAK,    XXXXXXX,  AG_NORM, AG_SWAP, XXXXXXX, RGB_HUD, RGB_HUI, AU_OFF, AU_ON,
      XXXXXXX, XXXXXXX, XXXXXXX,   COLEMAK,   XXXXXXX,  TERM_OFF,TERM_ON, XXXXXXX, RGB_SAD, RGB_SAI, MU_OFF, MU_ON,
      PLOVER,  XXXXXXX, XXXXXXX,   XXXXXXX,   _______,  XXXXXXX, XXXXXXX, _______, RGB_VAD, RGB_VAI, MUV_DE, MUV_IN
  ),


  //////////////////////////// Additional Default Layers ///////////////////////////////

  /* Colemak
  * ,-----------------------------------------------------------------------------------.
  * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
  * `-----------------------------------------------------------------------------------'
  */
  [_COLEMAK] = LAYOUT_planck_grid(
      KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
      KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
      BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  /* Dvorak
  * ,-----------------------------------------------------------------------------------.
  * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
  * `-----------------------------------------------------------------------------------'
  */
  [_DVORAK] = LAYOUT_planck_grid(
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
      KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
      KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
      BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  /* Plover layer (http://opensteno.org)
  * ,-----------------------------------------------------------------------------------.
  * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_PLOVER] = LAYOUT_planck_grid(
      KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
      XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
      XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
  ),

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
