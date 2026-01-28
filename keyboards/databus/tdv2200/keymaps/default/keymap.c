// Created/amended by OleVoip 2024.
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keymap_german.h"
#include "../../../databus.h"
#include "../../../databus-kb.h"
#include "keymap.h"

uint8_t detected_os = OS_UNSURE;
keycode_t compose_key = KC_CAPS;

#define n(key) DE_##key // national prefix, change according to host keymap
#define s(key) S(KC_##key)

#define X       KC_NO
#define MO_SFT  MO(KM_SHIFT)

enum custom_keycodes {
    KB_COMP = SAFE_RANGE,
    KB_LA1,
    KB_LA2,
    KB_LA3,
    KB_LA4
};

// clang-format off

/**
* \brief Keymaps for the 'International' layout, which is bit-paired ISO.
*/
FCONST keycode_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* ┌───────────────────────────────────────────────────────────────────────────────────────────────────────┐
 * │    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14       47  48  49  50  51  52  53  54     │
 * │   ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐ ┌───┬───┬───┐   ┌───┬───┬───┬───┐   │
 * │ G │ESC│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│   │     │ │PRT│SCR│PAU│   │   │   │   │BT │ G │
 * │   └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴─────┘ ├───┼───┼───┤   ├───┼───┼───┼───┤   │
 * │ F                                                                 │   │   │   │   │LA1│LA2│LA3│LA4│ F │
 * │   ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐ ├───┼───┼───┤   ├───┼───┼───┼───┤   │
 * │ E │ CAPS│ 1!│ 2"│ 3#│ 4$│ 5%│ 6&│ 7'│ 8(│ 9)│ 0_│ -=│ ^~│BS │DEL│ │INS│   │   │   │NUM│SLS│AST│MNS│ E │
 * │   ├───┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤ ├───┼───┼───┤   ├───┼───┼───┼───┤   │
 * │ D │ALT│TAB│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ @ │ [{│ALTGR│ │PUP│UP │PDN│   │ 7 │ 8 │ 9 │PLS│ D │
 * │   ├───┼───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┴┬──┴┬──┴┬──┴┬──┴─┬───┤ ├───┼───┼───┤   ├───┼───┼───┼───┤   │
 * │ C │CTL│LOCK│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ;+│ :*│ ]} │   │ │LFT│DN │RGT│   │ 5 │ 6 │ 7 │   │ C │
 * │   ├───┴──┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┤RET│ ├───┼───┼───┤   ├───┼───┼───┼───┤   │
 * │ B │ SHIFT│ \|│ Z │ X │ C │ V │ B │ N │ M │ ,<│ .>│ /?│SHIFT │   │ │HOM│   │END│   │ 1 │ 2 │ 3 │   │ B │
 * │   └──────┴───┴───┼───┴───┴───┴───┴───┴───┴───┴───┼───┴─┬───┬┴──┬┘ ├───┼───┼───┤   ├───┴───┼───┤ENT│   │
 * │ A      \    \    │              SPC              │  \             │   │   │   │   │   0   │ . │   │ A │
 * │                  └───────────────────────────────┘     └ ─ ┴ ─ ┘  └───┴───┴───┘   └───────┴───┴───┘   │
 * │         99   0   1   2   3   4   5   6   7   8   9   10   11  12   47  48  49  50  51  52  53  54     │
 * └───────────────────────────────────────────────────────────────────────────────────────────────────────┘
 *
 * 99   00      01    02    03     04    05    06    07     08      09     10      11      12      13      14    |47      48      49     |51     52      53      54 */
    [KM_DEFAULT] = LAYOUT_full(
        KC_ESC, KC_F1,KC_F2,KC_F3, KC_F4,KC_F5,KC_F6,KC_F7, KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12, X, QK_MACRO_0, KC_PSCR,KC_SCRL,KC_PAUS,X,     X,      KC_RCTL,QK_RBT,  // G
                                                                                                                  X,      X,      X,      KB_LA1,KB_LA2, KB_LA3, KB_LA4,  // F
        CW_TOGG,n(1), n(2), n(3),  n(4), n(5), n(6), n(7),  n(8),   n(9),  n(0),   n(MINS),n(CIRC),KC_BSPC,KC_DEL,KC_INS, KC_HOME,KC_PGUP,KC_NUM,KC_PSLS,KC_PAST,KC_PMNS, // E
KC_LALT,KC_TAB, n(Q), n(W), n(E),  n(R), n(T), n(Z), n(U),  n(I),   n(O),  n(P),   n(AT),  n(LBRC),KC_RALT,       KC_PGUP,KC_UP,  KC_PGDN,KC_P7, KC_P8,  KC_P9,  KC_PPLS, // D
KC_LCTL,KB_COMP,n(A), n(S), n(D),  n(F), n(G), n(H), n(J),  n(K),   n(L),  n(SCLN),n(COLN),n(RBRC),KC_ENT,        KC_LEFT,KC_DOWN,KC_RGHT,KC_P4, KC_P5,  KC_P6,  X,       // C
MO_SFT ,n(BSLS),n(Y), n(X), n(C),  n(V), n(B), n(N), n(M), n(COMM), n(DOT),n(SLSH),MO_SFT,                        KC_HOME,X,      KC_END, KC_P1, KC_P2,  KC_P3,  KC_PENT, // B
                                         KC_SPC,                                   KC_NO,  KC_NO,                 X,      X,      X,      KC_P0,         KC_PDOT       ), // A
    [KM_SHIFT] = LAYOUT_full(
        s(ESC),s(F1), s(1), s(F3), s(F4),s(F5),s(F6),s(F7), s(F8),  s(F9), s(F10), s(F11), s(F12), X,      X,     s(PSCR),s(SCRL),s(PAUS),X,     X,      X,      QK_BOOT, // G
                                                                                                                  X,      X,      X,      X,     X,      X,      X,       // F
        _______,s(1), s(2),n(HASH),s(4), s(5), s(6),n(QUOT),s(8),   s(9),  n(UNDS),n(EQL), n(TILD),s(BSPC),s(DEL),s(INS), s(HOME),s(PGUP),s(NUM),s(PSLS),s(PAST),s(PMNS), // E
s(LALT),s(TAB), s(Q), s(W), s(E),  s(R), s(T), s(Z), s(U),  s(I),   s(O),  s(P),   n(GRV), n(LCBR),s(RALT),       s(PGUP),s(UP),  s(PGDN),s(P7), s(P8),  s(P9),  s(PPLS), // D
s(LCTL),s(CAPS),s(A), s(S), s(D),  s(F), s(G), s(H), s(J),  s(K),   s(L),  n(PLUS),n(ASTR),n(RCBR),s(ENT),        s(LEFT),s(DOWN),s(RGHT),s(P4), s(P5),  s(P6),  X,       // C
_______,n(PIPE),s(Y), s(X), s(C),  s(V), s(B), s(N), s(M), n(LABK),n(RABK),n(QUES),s(RSFT),                       s(HOME),X,      s(END), s(P1), s(P2),  s(P3),  s(PENT), // B
                                         s(SPC),                                   KC_NO,  KC_NO,                 X,      X,      X,      s(P0),         s(PDOT)       )  // A
};

/** Minimal national layout
 * ┌───────────────────────────────────────────────────────────────────────────────────────────────────────┐
 * │    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14       47  48  49  50  51  52  53  54     │
 * │   ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐ ┌───┬───┬───┐   ┌───┬───┬───┬───┐   │
 * │ G │ESC│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│   │     │ │PRT│SCR│PAU│   │   │   │   │BT │ G │
 * │   └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴─────┘ ├───┼───┼───┤   ├───┼───┼───┼───┤   │
 * │ F                                                                 │   │   │   │   │   │   │   │   │ F │
 * │   ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐ ├───┼───┼───┤   ├───┼───┼───┼───┤   │
 * │ E │  GRV│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │BS │WIN│ │INS│HOM│PUP│   │NUM│SLS│AST│MNS│ E │
 * │   ├───┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤ ├───┼───┼───┤   ├───┼───┼───┼───┤   │
 * │ D │ALT│TAB│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ 9 │ALTGR│ │PUP│UP │PDN│   │ 7 │ 8 │ 9 │PLS│ D │
 * │   ├───┼───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┴┬──┴┬──┴┬──┴┬──┴─┬───┤ ├───┼───┼───┤   ├───┼───┼───┼───┤   │
 * │ C │CTL│LOCK│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ " │ #  │   │ │LFT│DN │RGT│   │ 5 │ 6 │ 7 │   │ C │
 * │   ├───┴──┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┤RET│ ├───┼───┼───┤   ├───┼───┼───┼───┤   │
 * │ B │ SHIFT│ \ │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │SHIFT │   │ │HOM│   │END│   │ 1 │ 2 │ 3 │   │ B │
 * │   └──────┴───┴───┼───┴───┴───┴───┴───┴───┴───┴───┼───┴─┬───┬┴──┬┘ ├───┼───┼───┤   ├───┴───┼───┤ENT│   │
 * │ A      \    \    │              SPC              │  \             │   │   │   │   │   0   │ . │   │ A │
 * │                  └───────────────────────────────┘     └ ─ ┴ ─ ┘  └───┴───┴───┘   └───────┴───┴───┘   │
 * │         99   0   1   2   3   4   5   6   7   8   9   10   11  12   47  48  49  50  51  52  53  54     │
 * └───────────────────────────────────────────────────────────────────────────────────────────────────────┘
 *
 * 99   00      01   02    03    04    05    06    07    08      09     10      11      12      13      14     |47      48      49     |51     52      53      54
        KC_ESC,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,  KC_F9, KC_F10, KC9_F11,KC_F12, X,      X,      KC_PSCR,KC_SCRL,KC_PAUS,X,     X,      X,      QK_BOOT, // G
                                                                                                                X,      X,      X,      X,     X,      X,      X,       // F
        KC_GRV, KC_1,KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,   KC_9,  KC_0,   KC_MINS,KC_EQL, KC_BSPC,KC_LWIN,KC_INS, KC_HOME,KC_PGUP,KC_NUM,KC_PSLS,KC_PAST,KC_PMNS, // E
KC_LALT,KC_TAB, KC_Q,KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,   KC_O,  KC_P,   KC_LBRC,KC_RBRC,KC_RALT,        KC_DEL, KC_END, KC_PGDN,KC_P7, KC_P8,  KC_P9,  KC_PPLS, // D
KC_LCTL,KC_CAPS,KC_A,KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,   KC_L,  KC_SCLN,KC_QUOT,KC_NUHS,KC_ENT,         X,      X,      X,      KC_P4, KC_P5,  KC_P6,  X,       // C
KC_LSFT,KC_BSLS,KC_Z,KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM,KC_DOT,KC_SLSH,KC_RSFT,                        X,      KC_UP,  X,      KC_P1, KC_P2,  KC_P3,  KC_PENT, // B
                                       KC_SPC,                                  X,      X,                      KC_LEFT,KC_DOWN,KC_RGHT,KC_P0,         KC_PDOT          // A
*/

/**
 * \brief Mapping of two-key combinations where typing order matters
 * Also mappings where both keys are the same go here as only one
 * combination needs to be checked
 */
FCONST two_key_seq_t fixed_seqs[] = {
};

/**
 * \brief Mapping of two-key combinations that may be entered in any order
 * Meaning that also the reversed order needs to be considered.
 */
FCONST two_key_seq_t any_order_seqs[] = {
};

static bool composing;
static keycode_t prev_keycode;
static uint8_t current_host;


void keyboard_pre_init_user(void) {
    debug_config.enable = true;
    debug_config.matrix = true;
    debug_config.keyboard = true;

    composing = false;
    prev_keycode = 0;
    current_host = 0;
}

const two_key_seq_t* find_seq(keycode_t kc1, keycode_t kc2) {
    const two_key_seq_t* mapping = &fixed_seqs[0];
    for (int8_t n = sizeof(fixed_seqs) / sizeof(two_key_seq_t); --n;) {
        if (mapping->kc1 == kc1 && (!kc2 || mapping->kc2 == kc2)) {
            return mapping;
        }
        mapping++;
    }

    mapping = &any_order_seqs[0];
    for (int8_t n = sizeof(any_order_seqs) / sizeof(two_key_seq_t); --n;) {
        if ((mapping->kc1 == kc1 && (!kc2 || mapping->kc2 == kc2)) ||
            (mapping->kc2 == kc1 && (!kc2 || mapping->kc1 == kc2))) {
            return mapping;
        }
        mapping++;
    }
    return NULL;
}

static inline bool process_record_composing(
    keycode_t keycode, keyrecord_t *record) {
    if (!record->event.pressed){
        return false;
    }
    const two_key_seq_t* seq = find_seq(keycode, prev_keycode);
    if (seq == NULL) {
        composing = false;
        if (compose_key != KC_NO) {
            tap_code16(compose_key);
        }
        if (prev_keycode) {
            tap_code16(prev_keycode);
        }
        return true;
    }
    if (!prev_keycode) {
        prev_keycode = keycode;
    } else {
        composing = false;
        // TODO: apply alt-code or unicode
    }
    return false;
}

bool process_record_user(keycode_t keycode, keyrecord_t *record) {
    if (composing && !process_record_composing(keycode, record)) {
        return false;
    }

    switch(keycode) {
        case KB_COMP:
            if (!record->event.pressed) {
                composing = true;
            }
            return false;

        case KB_LA1 ... KB_LA4: // KVM: switch host 1..4
            if (record->event.pressed) {
                indicators &= ~(1<<current_host);
                current_host = keycode - KB_LA1;
                uint16_t delay = 0;
                tap_code16_delay(KC_RCTL, delay);
                tap_code16_delay(KC_RCTL, delay);
                tap_code16_delay(KC_1 + current_host, delay);
                tap_code16_delay(KC_ENTER, delay);
                indicators |= (1<<current_host);
                update_indicators();
            }
            return false;

#ifdef CAPS_WORD_ENABLE
        case n(MINS):
            if (is_caps_word_on()){
                keycode = n(UNDS);
                if (record->event.pressed){
                    register_code16(keycode);
                } else {
                    unregister_code16(keycode);
                }
                return false;
            }
            return true;
#endif

        default:
            return true;
    }
}

bool process_detected_host_os_user(os_variant_t os) {
    detected_os = os;
    return true;
}


#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(keycode_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // apply shift
            break;

        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case n(UNDS):
            break; // unshifted

        default:
            return false; // deactivate caps_word
    }
    return true;
}
#endif

// .