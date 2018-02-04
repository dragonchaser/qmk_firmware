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

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

#define XXXX KC_NO
#define ____ KC_TRNS

bool music = true;

enum planck_layers {
  _DEFAULT,
  _FN
};

enum planck_keycodes {
  INS_1 = SAFE_RANGE,
  INS_2,
  INS_3,
  INS_4,
  INS_5,
  INS_6,
  T_MUS
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [0] = ACTION_TAP_DANCE_DOUBLE(KC_LSHIFT, KC_ENTER),
  [1] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_LCTRL)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DEFAULT] = {
  {KC_ESC ,KC_Q   ,KC_W   ,KC_E   ,KC_R                                        ,KC_T},
  {KC_TAB ,KC_A   ,KC_S   ,KC_D   ,KC_F                                        ,XXXX   ,KC_4   ,KC_5,    KC_6},
  {TD(0)  ,KC_Z   ,KC_X   ,KC_C   ,TD(1)  ,XXXX   ,KC_1   ,KC_2,    KC_3,    OSL(_FN)},
},

[_FN] = {
  {RESET  ,____   ,____   ,____   ,____    ,____},
  {____   ,____   ,____   ,____   ,____    ,____   ,INS_4   ,INS_5,    INS_6},
  {____   ,____   ,____   ,____   ,T_MUS    ,____   ,INS_1   ,INS_2,    INS_3,    TO(_DEFAULT)},
},

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
  float audio_on_sound[][2]   = SONG(AUDIO_ON_SOUND);
  float audio_off_sound[][2]  = SONG(AUDIO_OFF_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case T_MUS:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
        music = !music;
        if(music) {
          PLAY_SONG(audio_on_sound);
        } else {
          PLAY_SONG(audio_off_sound);
        }
        #endif
        layer_off(_FN);
      }
      return false; break;
    case INS_1:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          if(music) PLAY_SONG(plover_gb_song);
        #endif
        SEND_STRING("\nWell played!\n");
        layer_off(_FN);
      }
      return false;
      break;
    case INS_2:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          if(music) PLAY_SONG(plover_gb_song);
        #endif
        SEND_STRING("\nWhy are you dungholes always following the lemming train?\n");
        layer_off(_FN);
      }
      return false;
      break;
    case INS_3:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          if(music) PLAY_SONG(plover_gb_song);
        #endif
        SEND_STRING("\nYour mother was a hamster and your father smelled of elderberries!\n");
        layer_off(_FN);
      }
      return false;
      break;
    case INS_4:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          if(music) PLAY_SONG(plover_gb_song);
        #endif
        SEND_STRING("\nWhy don't go and you fuck yourself with a cactus!\n");
        layer_off(_FN);
      }
      return false;
      break;
    case INS_5:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          if(music) PLAY_SONG(plover_gb_song);
        #endif
        SEND_STRING("\nAre you really that supid?\n");
        layer_off(_FN);
      }
      return false;
      break;
    case INS_6:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          if(music) PLAY_SONG(plover_gb_song);
        #endif
        SEND_STRING("\nGet lost you friggin shitheads!\n");
        layer_off(_FN);
      }
      return false;
      break;
  }
  return true;
}
