// Created/amended by OleVoip 2024.
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keymap_german.h"
#include "../../../databus.h"
#include "keymap.h"

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
        KC_ESC, KC_F1,KC_F2,KC_F3, KC_F4,KC_F5,KC_F6,KC_F7, KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12, X, QK_MACRO_0, KC_PSCR,KC_SCRL,KC_PAUS,X,     X,      X,      QK_RBT,  // G
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
    {n(S),    n(M),      1, 0x25BA}, // ☺
    {n(B),    n(S),      2, 0x263B}, // ☻
    {n(H),    n(T),      3, 0x2665}, // ♥
    {n(D),    n(M),      4, 0x2666}, // ♦
    {n(C),    n(B),      5, 0x2663}, // ♣
    {n(S),    n(P),      6, 0x2660}, // ♠
    {n(C),    n(R),      9, 0x25CB}, // ○
    {n(M),    n(S),     11, 0x2642}, // ♂
    {n(V),    n(S),     12, 0x2640}, // ♀
    {n(E),    n(N),     13, 0x266A}, // ♪
    {n(E),    n(S),     14, 0x266B}, // ♫
    {n(S),    n(N),     15, 0x263C}, // ☼
    {n(D),    n(EXLM),  19, 0x203C}, // ‼
    {n(EQL),  n(EQL),   22, 0x25AC}, // ▬
    {n(MINS), n(LABK),  26, 0x2192}, // →
    {n(RABK), n(MINS),  27, 0x2190}, // ←
    {n(LABK), n(RABK),  29, 0x2194}, // ↔
    {n(F),    n(F),    131, 0x0192}, // ƒ
    {n(DOT),  n(DOT),  133, 0x2026}, // …
    {n(D),    n(D),    135, 0x2021}, // ‡
    {n(CIRC), n(CIRC), 136, 0x02C6}, // ˆ
    {n(PERC), n(O),    137, 0x2030}, // ‰
    {n(V),    s(S),    138, 0x0160}, // Š
    {s(O),    s(E),    140, 0x0152}, // Œ
    {n(V),    s(Z),    142, 0x017D}, // Ž
    {n(T),    n(M),    153, 0x2122}, // ™
    {n(V),    n(S),    154, 0x0161}, // š
    {n(O),    n(E),    156, 0x0153}, // œ
    {n(V),    n(Z),    158, 0x017E}, // ž
    {n(N),    n(B),    160, 0x00A0}, // nbsp
    {n(EXLM), n(EXLM), 161, 0x00A1}, // ¡
    {n(DQUO), n(DQUO), 168, 0x00A8}, // ¨
    {n(LABK), n(LABK), 171, 0x00AB}, // «
    {n(MINS), n(COMM), 172, 0x00AC}, // ¬
    {n(O),    n(O),    176, 0x00B0}, // °
    {n(PLUS), n(MINS), 177, 0x00B1}, // ±
    {n(P),    n(EXLM), 182, 0x00B6}, // ¶
    {n(COMM), n(COMM), 184, 0x00B8}, // ¸
    {n(RABK), n(RABK), 187, 0x00BB}, // »
    {n(1),    n(4),    188, 0x00BC}, // ¼
    {n(1),    n(2),    189, 0x00BD}, // ½
    {n(3),    n(4),    190, 0x00BE}, // ¾
    {n(QUES), n(QUES), 191, 0x00BF}, // ¿
    {s(A),    s(E),    198, 0x00C6}, // Æ
    {s(C),    n(COMM), 199, 0x00C7}, // Ç
    {s(D),    s(H),    208, 0x00D0}, // Ð
    {n(X),    n(X),    215, 0x00D7}, // ×
    {s(T),    s(H),    222, 0x00DE}, // Þ
    {n(S),    n(S),    223, 0x00DF}, // ß
    {n(D),    n(H),    240, 0x00F0}, // ð
    {n(T),    n(H),    254, 0x00FE}  // þ
};

/**
 * \brief Mapping of two-key combinations that may be entered in any order
 * Meaning that also the reversed order needs to be considered.
 */
FCONST two_key_seq_t any_order_seqs[] = {
    {n(R),    n(P),     16, 0x25BA}, // ►
    {n(L),    n(P),     17, 0x25C4}, // ◄
    {n(U),    n(D),     18, 0x2195}, // ↕
    {n(PIPE), n(B),     23, 0x21A8}, // ↨
    {n(PIPE), n(CIRC),  24, 0x2195}, // ↑
    {n(PIPE), n(V),     25, 0x2193}, // ↓
    {n(U),    n(P),     30, 0x25B2}, // ▲
    {n(D),    n(P),     31, 0x25BC}, // ▼
    {n(C),    n(EQL),  128, 0x20AC}, // €
    {n(COMM), n(QUOT), 130, 0x201A}, // ‚
    {n(COMM), n(DQUO), 132, 0x201E}, // „
    {n(S),    n(D),    134, 0x2020}, // †
    {n(DOT),  n(LABK), 139, 0x2039}, // ‹
    {n(LABK), n(QUOT), 145, 0x2018}, // ‘
    {n(RABK), n(QUOT), 146, 0x2019}, // ’
    {n(LABK), n(DQUO), 147, 0x201C}, // “
    {n(RABK), n(DQUO), 148, 0x201D}, // ”
    {n(DOT),  n(EQL),  149, 0x2022}, // •
    {n(MINS), n(DOT),  150, 0x2013}, // –
    {n(MINS), n(UNDS), 151, 0x2014}, // —
    {n(CIRC), n(TILD), 152, 0x02DC}, // ˜
    {n(DOT),  n(RABK), 155, 0x203A}, // ›
    {n(COLN), s(Y),    159, 0x0178}, // Ÿ
    {n(DQUO), s(Y),    159, 0x0178}, // Ÿ
    {n(C),    n(SLSH), 162, 0x00A2}, // ¢
    {n(L),    n(MINS), 163, 0x00A3}, // £
    {n(X),    n(O),    164, 0x00A4}, // ¤
    {n(Y),    n(EQL),  165, 0x00A5}, // ¥
    {n(EXLM), n(CIRC), 166, 0x00A6}, // ¦
    {n(S),    n(O),    167, 0x00A7}, // §
    {n(CIRC), n(COLN), 168, 0x00A8}, // ¨
    {n(O),    n(C),    169, 0x00A9}, // ©
    {n(A),    n(UNDS), 170, 0x00AA}, // ª
    {n(MINS), KC_SPC,  173, 0x00AD}, // shy
    {n(O),    n(R),    174, 0x00AE}, // ®
    {n(CIRC), n(MINS), 175, 0x00AF}, // ¯
    {n(CIRC), n(2),    178, 0x00B2}, // ²
    {n(CIRC), n(3),    179, 0x00B3}, // ³
    {n(QUOT), KC_SPC,  180, 0x00B4}, // ´
    {n(SLSH), n(U),    181, 0x00B5}, // μ
    {n(DOT),  n(MINS), 183, 0x00B7}, // ·
    {n(CIRC), n(1),    185, 0x00B9}, // ¹
    {n(O),    n(UNDS), 186, 0x00BA}, // º
    {n(GRV),  s(A),    192, 0x00C0}, // À
    {n(QUOT), s(A),    193, 0x00C1}, // Á
    {n(CIRC), s(A),    194, 0x00C2}, // Â
    {n(TILD), s(A),    195, 0x00C3}, // Ã
    {n(COLN), s(A),    196, 0x00C4}, // Ä
    {n(DQUO), s(A),    196, 0x00C4}, // Ä
    {n(ASTR), s(A),    197, 0x00C5}, // Å
    {n(GRV),  s(E),    200, 0x00C8}, // È
    {n(QUOT), s(E),    201, 0x00C9}, // É
    {n(CIRC), s(E),    202, 0x00CA}, // Ê
    {n(COLN), s(E),    203, 0x00CB}, // Ë
    {n(DQUO), s(E),    203, 0x00CB}, // Ë
    {n(GRV),  s(I),    204, 0x00CC}, // Ì
    {n(QUOT), s(I),    205, 0x00CD}, // Í
    {n(CIRC), s(I),    206, 0x00CE}, // Î
    {n(COLN), s(I),    207, 0x00CF}, // Ï
    {n(DQUO), s(I),    207, 0x00CF}, // Ï
    {n(TILD), s(N),    209, 0x00D1}, // Ñ
    {n(GRV),  s(O),    210, 0x00D2}, // Ò
    {n(QUOT), s(O),    211, 0x00D3}, // Ó
    {n(CIRC), s(O),    212, 0x00D4}, // Ô
    {n(TILD), s(O),    213, 0x00D5}, // Õ
    {n(COLN), s(O),    214, 0x00D6}, // Ö
    {n(DQUO), s(O),    214, 0x00D6}, // Ö
    {s(O),    n(SLSH), 216, 0x00D8}, // Ø
    {n(GRV),  s(U),    217, 0x00D9}, // Ù
    {n(QUOT), s(U),    218, 0x00DA}, // Ú
    {n(CIRC), s(U),    219, 0x00DB}, // Û
    {n(COLN), s(U),    220, 0x00DC}, // Ü
    {n(DQUO), s(U),    220, 0x00DC}, // Ü
    {n(QUOT), s(Y),    221, 0x00DD}, // Ý
    {n(GRV),  n(A),    224, 0x00E0}, // à
    {n(QUOT), n(A),    225, 0x00E1}, // á
    {n(CIRC), n(A),    226, 0x00E2}, // â
    {n(TILD), n(A),    227, 0x00E3}, // ã
    {n(COLN), n(A),    228, 0x00E4}, // ä
    {n(DQUO), n(A),    228, 0x00E4}, // ä
    {n(ASTR), n(A),    229, 0x00E5}, // å
    {n(A),    n(E),    230, 0x00E6}, // æ
    {n(C),    n(COMM), 231, 0x00E7}, // ç
    {n(GRV),  n(E),    232, 0x00E8}, // è
    {n(QUOT), n(E),    233, 0x00E9}, // é
    {n(CIRC), n(E),    234, 0x00EA}, // ê
    {n(COLN), n(E),    235, 0x00EB}, // ë
    {n(DQUO), n(E),    235, 0x00EB}, // ë
    {n(GRV),  n(I),    236, 0x00EC}, // ì
    {n(QUOT), n(I),    237, 0x00ED}, // í
    {n(CIRC), n(I),    238, 0x00EE}, // î
    {n(COLN), n(I),    239, 0x00EF}, // ï
    {n(DQUO), n(I),    239, 0x00EF}, // ï
    {n(TILD), n(N),    241, 0x00F1}, // ñ
    {n(GRV),  n(O),    242, 0x00F2}, // ò
    {n(QUOT), n(O),    243, 0x00F3}, // ó
    {n(CIRC), n(O),    244, 0x00F4}, // ô
    {n(TILD), n(O),    245, 0x00F5}, // õ
    {n(COLN), n(O),    246, 0x00F6}, // ö
    {n(DQUO), n(O),    246, 0x00F6}, // ö
    {n(COLN), n(MINS), 247, 0x00F7}, // ÷
    {n(SLSH), n(O),    248, 0x00F8}, // ø
    {n(GRV),  n(U),    249, 0x00F9}, // ù
    {n(QUOT), n(U),    250, 0x00FA}, // ú
    {n(CIRC), n(U),    251, 0x00FB}, // û
    {n(COLN), n(U),    252, 0x00FC}, // ü
    {n(DQUO), n(U),    252, 0x00FC}, // ü
    {n(QUOT), n(Y),    253, 0x00FD}, // ý
    {n(COLN), n(Y),    255, 0x00FF}, // ÿ
    {n(DQUO), n(Y),    255, 0x00FF}, // ÿ
};

static bool composing;
static keycode_t prev_keycode;

void keyboard_pre_init_user(void) {
    debug_config.enable = true;
    debug_config.matrix = true;
    debug_config.keyboard = true;

    composing = false;
    prev_keycode = 0;
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
                tap_code16(KC_SCRL);
                tap_code16(KC_SCRL);
                tap_code16(KC_1 + (keycode - KB_LA1));
                tap_code16(KC_ENTER);
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
            }
            return false;
#endif

        default:
            return true;
    }
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
            return false; // deactivate Caps Word.
    }
    return true;
}
#endif

// .