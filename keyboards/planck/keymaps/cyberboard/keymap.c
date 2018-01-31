#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;
int a = 0;
#define insult_count 6

const char* insults[] = {
  "Go fuck yourself with a cactus!\n",
  "Have your parents considered post-natal abortion?\n",
  "Are your really that stupid?\n",
  "Oh for fucks sake!\n",
  "Your mother is a hamster and your father smelt of elderberries!\n",
  "BOOLSHIT!\n"
};

enum planck_layers {
  _DEFAULT
};

enum planck_keycodes {
  BOOLSHIT = SAFE_RANGE,
  DESKTOP_1,
  DESKTOP_2,
  DESKTOP_3,
  DESKTOP_4,
  DESKTOP_5
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DEFAULT] = {
  {KC_AUDIO_VOL_DOWN    ,KC_AUDIO_VOL_UP    ,KC_AUDIO_MUTE          ,BOOLSHIT               ,KC_PGUP},
  {KC_MEDIA_PREV_TRACK  ,KC_MEDIA_STOP      ,KC_MEDIA_PLAY_PAUSE    ,KC_MEDIA_NEXT_TRACK    ,KC_PGDOWN},
  {DESKTOP_1            ,DESKTOP_2          ,DESKTOP_3              ,DESKTOP_4              ,DESKTOP_5}
},

};

#ifdef AUDIO_ENABLE
  float insult_song[][2]         = SONG(VIOLIN_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case BOOLSHIT:
        PLAY_SONG(insult_song);
        send_string(insults[a++]);
      return false;
      break;
      case DESKTOP_1:
        SEND_STRING(SS_LGUI("1"));
      return false;
      break;
      case DESKTOP_2:
        SEND_STRING(SS_LGUI("2"));
      return false;
      break;
      case DESKTOP_3:
        SEND_STRING(SS_LGUI("3"));
      return false;
      break;
      case DESKTOP_4:
        SEND_STRING(SS_LGUI("4"));
      return false;
      break;
      case DESKTOP_5:
        SEND_STRING(SS_LGUI("5"));
      return false;
      break;
    }   
  }
  if(a > insult_count - 1) a = 0;
  return true;
}
