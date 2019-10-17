#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  DYNAMIC_MACRO_RANGE,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#include "dynamic_macro.h"

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(KC_TAB,KC_QUOTE,KC_COMMA,KC_DOT,KC_P,KC_Y,KC_F,KC_G,KC_C,KC_R,KC_L,KC_BSPACE,KC_ESCAPE,KC_A,KC_O,KC_E,KC_U,KC_I,KC_D,KC_H,KC_T,KC_N,KC_S,KC_ENTER,KC_LSPO,KC_SCOLON,KC_Q,KC_J,KC_K,KC_X,KC_B,KC_M,KC_W,KC_V,KC_Z,KC_RSPC,LCTL_T(KC_CAPSLOCK),KC_LGUI,KC_LALT,DYN_MACRO_PLAY1,LOWER,KC_SPACE,KC_NO,RAISE,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT),

  [_LOWER] = LAYOUT_planck_grid(KC_ESCAPE,KC_PERC,KC_AT,KC_KP_MINUS,KC_KP_SLASH,KC_BSLASH,KC_UNDS,KC_KP_7,KC_KP_8,KC_KP_9,KC_EQUAL,KC_BSPACE,KC_TAB,KC_EXLM,KC_QUES,KC_KP_PLUS,KC_KP_ASTERISK,KC_LBRACKET,KC_RBRACKET,KC_KP_4,KC_KP_5,KC_KP_6,KC_KP_0,KC_KP_ENTER,KC_LSPO,KC_DLR,KC_HASH,KC_AMPR,KC_CIRC,KC_LCBR,KC_RCBR,KC_KP_1,KC_KP_2,KC_KP_3,KC_KP_DOT,KC_RSPC,KC_LCTRL,KC_LGUI,KC_LALT,KC_TRANSPARENT,KC_TRANSPARENT,KC_SPACE,KC_NO,KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT),

  [_RAISE] = LAYOUT_planck_grid(KC_TAB,KC_AUDIO_VOL_UP,LCTL(KC_PGUP),KC_UP,LCTL(KC_PGDOWN),KC_PGUP,KC_MS_WH_UP,KC_MS_BTN1,KC_MS_UP,KC_MS_BTN2,KC_MS_BTN3,KC_BSPACE,KC_ESCAPE,KC_AUDIO_VOL_DOWN,KC_LEFT,KC_DOWN,KC_RIGHT,KC_PGDOWN,KC_MS_WH_DOWN,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_MS_BTN4,KC_ENTER,KC_LSPO,KC_PC_UNDO,KC_PC_CUT,KC_PC_COPY,KC_PC_PASTE,KC_FIND,KC_F12,KC_NONUS_HASH,KC_NONUS_BSLASH,KC_PGUP,KC_MS_BTN5,KC_RSPC,LCTL_T(KC_CAPSLOCK),KC_LGUI,KC_LALT,KC_TRANSPARENT,KC_TRANSPARENT,KC_SPACE,KC_NO,KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_UP,KC_MEDIA_PLAY_PAUSE),

  [_ADJUST] = LAYOUT_planck_grid(KC_TAB,KC_F12,KC_F11,KC_F10,KC_F9,KC_TRANSPARENT,KC_TRANSPARENT,KC_F15,KC_F18,KC_F21,KC_F24,KC_BSPACE,KC_ESCAPE,KC_F8,KC_F7,KC_F6,KC_F5,DYN_REC_START1,DYN_REC_STOP,KC_F14,KC_F17,KC_F20,KC_F23,KC_ENTER,KC_LSPO,KC_F4,KC_F3,KC_F2,KC_F1,KC_TRANSPARENT,KC_TRANSPARENT,KC_F13,KC_F16,KC_F19,KC_F22,KC_RSPC,LCTL_T(KC_CAPSLOCK),KC_LGUI,KC_LALT,KC_TRANSPARENT,KC_TRANSPARENT,KC_SPACE,KC_NO,KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT),

};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {0,0,0}, {14,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [1] = { {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255} },

    [2] = { {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255} },

    [3] = { {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

#ifdef AUDIO_ENABLE
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
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
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
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
