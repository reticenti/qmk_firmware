#include "clueboard.h"
#include <stdarg.h>

// Helpful defines
#define GRAVE_MODS  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))
#define _______ KC_TRNS


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
#define _CL 2
#define _ML 3
#define _KL 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: Base Layer (Default Layer)
   */
[_BL] = KEYMAP(
  F(0),    KC_1,      KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,     KC_MINS,  KC_EQL,    KC_GRV,  KC_BSPC,          KC_PGUP,         \
  KC_TAB,  KC_Q,      KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,                   KC_PGDN,         \
  F(3), KC_A,      KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS,   KC_ENT,                                     \
  MO(_FL), KC_LSHIFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,   KC_SLSH,  KC_RSHIFT, OSL(_ML),                   KC_UP,          \
  KC_LCTL, KC_LEAD,   KC_LGUI, KC_LALT,          KC_SPC,KC_SPC,                         KC_RALT,  KC_CAPS,  OSL(_KL),  KC_RCTRL	,        KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap _FL: Function Layer
   */
[_FL] = KEYMAP(
  KC_GRV,  KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10 ,  KC_F11 ,  KC_F12 ,  _______, KC_DEL,              BL_STEP,        \
  _______, _______, _______,_______,_______,_______,_______,_______,KC_PSCR,KC_SLCK, KC_PAUS,  BL_OFF ,  BL_ON  ,  _______,                      BL_TOGG,        \
  _______, _______, MO(_CL),_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                                      \
  MO(_FL), _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                      KC_PGUP,        \
  _______, _______, _______, _______,       _______,_______,                         _______,  _______,  _______,  _______,            KC_HOME,  KC_PGDN, KC_END),

  /* Keymap _CL: Control layer
   */
[_CL] = KEYMAP(
  _______, _______, _______,_______,_______,_______,_______,_______,_______,  _______, _______,  _______,  _______,  _______,  RGB_TOG,              RGB_VAI,           \
  _______, _______, _______,_______,RESET,  _______,_______,_______,_______,  _______, _______,  _______,  _______,  _______,                        RGB_VAD,           \
  _______, _______, MO(_CL),_______,_______,_______,_______,_______,_______,  _______, _______,  _______,  _______,  _______,                                           \
  MO(_FL), _______, _______,_______,_______,_______,_______,MAGIC_TOGGLE_NKRO,_______, _______,  _______,  _______,  _______,  OSL(_ML),             RGB_SAI,           \
  _______, _______, _______,_______,        RGB_MOD,   RGB_MOD,                                  _______,  _______,  _______,  _______, RGB_HUD,     RGB_SAD,    RGB_HUI), 

  /* Keymap _ML: Media layer
   */
[_ML] = KEYMAP(
  _______, _______, _______,_______,_______, _______,_______,_______,_______,_______, _______,  _______,  _______,   _______ ,  KC_MUTE,    KC_VOLU,        \
  _______, _______, _______,_______,_______, _______,_______,_______,_______,_______, _______,  _______,  _______,   _______ ,              KC_VOLD,        \
  _______, _______, _______,_______,_______, _______,_______,_______,_______,_______, _______,  _______,  _______,   _______ ,                              \
  _______, _______, _______,_______,_______, _______,_______,_______,_______,_______, _______,  _______,  _______,   OSL(_ML),              KC_MPLY,        \
  _______, _______, _______,_______,        _______,   _______,                       _______,  _______,  _______,   _______ ,  KC_MPRV,    KC_MSTP,KC_MNXT),
  
  /* K Layer
	This area has access to functions that  setup in advanced. Hopefullly this area will also be represented by the leader key command functions.
  */
  [_KL] = KEYMAP(
  _______, _______, _______,_______,_______, _______,_______,_______,_______,_______, _______,  _______,   _______,  _______, _______,             _______,        \
  _______, _______, _______,_______,_______, _______,_______,_______,_______,_______, _______,  _______,   F(2)   ,  F(1)   ,                      _______,        \
  _______, _______, _______,_______,_______, _______,_______,_______,_______,_______, _______,  _______,   _______,  _______,                                      \
  _______, _______, _______,_______,_______, _______,_______,MAGIC_HOST_NKRO,_______, _______,  _______,   _______,  _______, _______,             _______,        \
  _______, _______, MAGIC_NO_GUI,_______,        _______,   _______,                  _______,  MAGIC_UNNO_GUI,     OSL(_KL), _______, _______,    _______,_______),
  
  
};


#define TAP_ONCE(code)  \
  register_code (code); \
  unregister_code (code)

/*Leader Key Mappings 
*/
LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

	//send username
    SEQ_ONE_KEY(KC_R) {
      SEND_STRING("reti");
    }
	
	//open app choser
	SEQ_ONE_KEY(KC_LGUI) { 
      register_code(KC_LCTRL); 
	  register_code(KC_LALT);
	  register_code(KC_TAB);
      unregister_code(KC_LCTRL); 
	  unregister_code(KC_LALT);
	  unregister_code(KC_TAB);
    }
	
	// vim style delete line
    SEQ_TWO_KEYS(KC_D, KC_L) {
      TAP_ONCE(KC_HOME);
      register_code(KC_LSHIFT);
	  TAP_ONCE(KC_END);
	  unregister_code(KC_LSHIFT);
	  TAP_ONCE(KC_DEL);
    }
	
	// vim style delete word
    SEQ_TWO_KEYS(KC_D, KC_W) {
      register_code(KC_LCTRL);
	  register_code(KC_LSHIFT);
	  TAP_ONCE(KC_RIGHT);
	  unregister_code(KC_LSHIFT);
	  unregister_code(KC_LCTRL);
	  TAP_ONCE(KC_DEL);
    }
	
	// <leader>asd goes to search
    SEQ_THREE_KEYS(KC_A, KC_S, KC_D) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
    
	SEQ_ONE_KEY(KC_L) {
		backlight_set(9);
	}
  }
}

/* This is a list of user defined functions. F(N) corresponds to item N
   of this list.
 */
const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_FUNCTION(0),  // Calls action_function()
  [1] = ACTION_FUNCTION(1),
  [2] = ACTION_FUNCTION(2),
  [3] = ACTION_FUNCTION(3),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t mods_pressed;
  static bool mod_flag;

  switch (id) {
    case 0:
      /* Handle the combined Grave/Esc key
       */
      mods_pressed = get_mods()&GRAVE_MODS; // Check to see what mods are pressed

      if (record->event.pressed) {
        /* The key is being pressed.
         */
        if (mods_pressed) {
          mod_flag = true;
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        /* The key is being released.
         */
        if (mod_flag) {
          mod_flag = false;
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
	  
	case 1:
	  if (record->event.pressed) {
	    TAP_ONCE(KC_1);
	    TAP_ONCE(KC_4);
	    TAP_ONCE(KC_7);
	    TAP_ONCE(KC_8);
	  }
	  break;
	  
	case 2:
	  if (record->event.pressed) {
	    TAP_ONCE(KC_1);
	    TAP_ONCE(KC_4);
	    TAP_ONCE(KC_7);
	    TAP_ONCE(KC_8);
	    TAP_ONCE(KC_9);
	    TAP_ONCE(KC_6);
	    TAP_ONCE(KC_3);
	    TAP_ONCE(KC_2);
	  }
	  break;
	  
	case 3:
	  if (record->event.pressed) {
	    register_code(KC_LSHIFT);
		register_code(KC_L);
		unregister_code(KC_LSHIFT);
		unregister_code(KC_L);
	  }
	  break;
  }
}

/*
Generic Keymap

[FN] = KEYMAP(
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,  _______,        \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,          _______,        \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,                          \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,          _______,        \
  _______,_______,_______,_______,        _______,   _______,                     _______,_______,_______,_______,_______,  _______,_______),
  
  
  */
