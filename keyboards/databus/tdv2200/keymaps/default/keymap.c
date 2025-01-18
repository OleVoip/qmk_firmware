// Created/amended by OleVoip 2024.
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keymap_german.h"
#include "../../../databus.h"
#include "keymap.h"

#define k(key) DE_##key // change prefix according to host keymap
#define s(key) S(KC_##key)

#define X       KC_NO
#define MO_SFT  MO(KM_SHIFT)

// clang-format off

FCONST uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// ┌───────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14       47  48  49  50  51  52  53  54     │
// │   ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐ ┌───┬───┬───┐   ┌───┬───┬───┬───┐   │
// │ G │ESC│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│   │     │ │PRT│SCR│PAU│   │   │   │   │BT │ G │
// │   └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴─────┘ ├───┼───┼───┤   ├───┼───┼───┼───┤   │
// │ F                                                                 │   │   │   │   │   │   │   │   │ F │
// │   ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐ ├───┼───┼───┤   ├───┼───┼───┼───┤   │
// │ E │ CAPS│ 1!│ 2"│ 3#│ 4$│ 5%│ 6&│ 7'│ 8(│ 9)│ 0_│ -=│ ^~│BS │DEL│ │INS│   │   │   │NUM│SLS│AST│MNS│ E │
// │   ├───┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤ ├───┼───┼───┤   ├───┼───┼───┼───┤   │
// │ D │ALT│TAB│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ @ │ [{│ALTGR│ │PUP│UP │PDN│   │ 7 │ 8 │ 9 │PLS│ D │
// │   ├───┼───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┴┬──┴┬──┴┬──┴┬──┴─┬───┤ ├───┼───┼───┤   ├───┼───┼───┼───┤   │
// │ C │CTL│LOCK│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ;+│ :*│ ]} │   │ │LFT│DN │RGT│   │ 5 │ 6 │ 7 │   │ C │
// │   ├───┴──┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┤RET│ ├───┼───┼───┤   ├───┼───┼───┼───┤   │
// │ B │ SHIFT│ \|│ Z │ X │ C │ V │ B │ N │ M │ ,<│ .>│ /?│SHIFT │   │ │HOM│   │END│   │ 1 │ 2 │ 3 │   │ B │
// │   └──────┴───┴───┼───┴───┴───┴───┴───┴───┴───┴───┼───┴─┬───┬┴──┬┘ ├───┼───┼───┤   ├───┴───┼───┤ENT│   │
// │ A      \    \    │              SPC              │  \             │   │   │   │   │   0   │ . │   │ A │
// │                  └───────────────────────────────┘     └ ─ ┴ ─ ┘  └───┴───┴───┘   └───────┴───┴───┘   │
// │         99   0   1   2   3   4   5   6   7   8   9   10   11  12   47  48  49  50  51  52  53  54     │
// └───────────────────────────────────────────────────────────────────────────────────────────────────────┘
// 99   00      01    02    03     04    05    06    07     08      09     10      11      12      13      14    |47      48      49     |51     52      53      54
    [KM_DEFAULT] = LAYOUT_full(
        KC_ESC, KC_F1,KC_F2,KC_F3, KC_F4,KC_F5,KC_F6,KC_F7, KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12, X, QK_MACRO_0, KC_PSCR,KC_SCRL,KC_PAUS,X,     X,      X,      X,       // G
                                                                                                                  X,      X,      X,      X,     X,      X,      X,       // F
        CW_TOGG,k(1), k(2), k(3),  k(4), k(5), k(6), k(7),  k(8),   k(9),  k(0),   k(MINS),k(CIRC),KC_BSPC,KC_DEL,KC_INS, KC_HOME,KC_PGUP,KC_NUM,KC_PSLS,KC_PAST,KC_PMNS, // E
KC_LALT,KC_TAB, k(Q), k(W), k(E),  k(R), k(T), k(Z), k(U),  k(I),   k(O),  k(P),   k(AT),  k(LBRC),KC_RALT,       KC_PGUP,KC_UP,  KC_PGDN,KC_P7, KC_P8,  KC_P9,  KC_PPLS, // D
KC_LCTL,KC_CAPS,k(A), k(S), k(D),  k(F), k(G), k(H), k(J),  k(K),   k(L),  k(SCLN),k(COLN),k(RBRC),KC_ENT,        KC_LEFT,KC_DOWN,KC_RGHT,KC_P4, KC_P5,  KC_P6,  X,       // C
MO_SFT ,k(BSLS),k(Y), k(X), k(C),  k(V), k(B), k(N), k(M), k(COMM), k(DOT),k(SLSH),MO_SFT,                        KC_HOME,X,      KC_END, KC_P1, KC_P2,  KC_P3,  KC_PENT, // B
                                         KC_SPC,                                   KC_NO,  KC_NO,                 X,      X,      X,      KC_P0,         KC_PDOT ),       // A
    [KM_SHIFT] = LAYOUT_full(
        s(ESC),s(F1), s(1), s(F3), s(F4),s(F5),s(F6),s(F7), s(F8),  s(F9), s(F10), s(F11), s(F12), X,      X,     s(PSCR),s(SCRL),s(PAUS),X,     X,      X,      QK_BOOT, // G
                                                                                                                  X,      X,      X,      X,     X,      X,      X,       // F
        _______,s(1), s(2),k(HASH),s(4), s(5), s(6),k(QUOT),s(8),   s(9),  k(UNDS),k(EQL), k(TILD),s(BSPC),s(DEL),s(INS), s(HOME),s(PGUP),s(NUM),s(PSLS),s(PAST),s(PMNS), // E
s(LALT),s(TAB), s(Q), s(W), s(E),  s(R), s(T), s(Z), s(U),  s(I),   s(O),  s(P),   k(GRV), k(LCBR),s(RALT),       s(PGUP),s(UP),  s(PGDN),s(P7), s(P8),  s(P9),  s(PPLS), // D
s(LCTL),s(CAPS),s(A), s(S), s(D),  s(F), s(G), s(H), s(J),  s(K),   s(L),  k(PLUS),k(ASTR),k(RCBR),s(ENT),        s(LEFT),s(DOWN),s(RGHT),s(P4), s(P5),  s(P6),  X,       // C
_______,k(PIPE),s(Y), s(X), s(C),  s(V), s(B), s(N), s(M), k(LABK),k(RABK),k(QUES),s(RSFT),                       s(HOME),X,      s(END), s(P1), s(P2),  s(P3),  s(PENT), // B
                                         s(SPC),                                   KC_NO,  KC_NO,                 X,      X,      X,      s(P0),         s(PDOT)          // A
    )
/*
    [KM_DFT] = LAYOUT_full(
//   0   1   2   3   4   5   6   7   8   9  10  11  12  13  14      47  48  49     51  52  53  54
// ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐ ┌───┬───┬───┐  ┌───┬───┬───┬───┐
// │ESC│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│   │     │ │PRT│SCR│PAU│  │   │   │   │BT │ G
// └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴─────┘ ├───┼───┼───┤  ├───┼───┼───┼───┤
//                                                                 │   │   │   │  │   │   │   │   │ F
// ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐ ├───┼───┼───┤  ├───┼───┼───┼───┤
// │  GRV│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │BS │WIN│ │INS│HOM│PUP│  │NUM│SLS│AST│MNS│ E
// ├───┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤ ├───┼───┼───┤  ├───┼───┼───┼───┤
// │ALT│TAB│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ALTGR│ │DEL│END│PDN│  │ 7 │ 8 │ 9 │PLS│ D
// ├───┼───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┴┬──┴┬──┴┬──┴┬──┴─┬───┤ ├───┼───┼───┤  ├───┼───┼───┼───┤
// │CTL│CAPS│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ " │ #  │   │ │   │   │   │  │ 5 │ 6 │ 7 │   │ C
// ├───┴──┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┤RET│ ├───┼───┼───┤  ├───┼───┼───┼───┤
// │ SHIFT│ \ │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │SHIFT │   │ │   │UP │   │  │ 1 │ 2 │ 3 │   │ B
// └──────┴───┴───┼───┴───┴───┴───┴───┴───┴───┴───┼───┴─┬───┬┴──┬┘ ├───┼───┼───┤  ├───┴───┼───┤ENT│
//                │              SPC              │                │LFT│DN │RGT│  │   0   │ . │   │ A
//                └───────────────────────────────┘     └ ─ ┴ ─ ┘  └───┴───┴───┘  └───────┴───┴───┘
//
// 99   00      01   02    03    04    05    06    07    08      09     10      11      12      13      14     |47      48      49     |51     52      53      54
        KC_ESC,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,  KC_F9, KC_F10, KC9_F11,KC_F12, X,      X,      KC_PSCR,KC_SCRL,KC_PAUS,X,     X,      X,      QK_BOOT, // G
                                                                                                                X,      X,      X,      X,     X,      X,      X,       // F
        KC_GRV, KC_1,KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,   KC_9,  KC_0,   KC_MINS,KC_EQL, KC_BSPC,KC_LWIN,KC_INS, KC_HOME,KC_PGUP,KC_NUM,KC_PSLS,KC_PAST,KC_PMNS, // E
KC_LALT,KC_TAB, KC_Q,KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,   KC_O,  KC_P,   KC_LBRC,KC_RBRC,KC_RALT,        KC_DEL, KC_END, KC_PGDN,KC_P7, KC_P8,  KC_P9,  KC_PPLS, // D
KC_LCTL,KC_CAPS,KC_A,KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,   KC_L,  KC_SCLN,KC_QUOT,KC_NUHS,KC_ENT,         X,      X,      X,      KC_P4, KC_P5,  KC_P6,  X,       // C
KC_LSFT,KC_BSLS,KC_Z,KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM,KC_DOT,KC_SLSH,KC_RSFT,                        X,      KC_UP,  X,      KC_P1, KC_P2,  KC_P3,  KC_PENT, // B
                                       KC_SPC,                                  X,      X,                      KC_LEFT,KC_DOWN,KC_RGHT,KC_P0,         KC_PDOT          // A
    )
*/
};

/**
 * \brief Mapping of two-key combinations where typing order matters
 * Also mappings where both keys are the same go here as only one
 * combination needs to be checked
 */
FCONST two_key_mapping_t fixed_sequence_combinations[] = {
    {k(S),    k(M),      1, 0x25BA}, // ☺
    {k(B),    k(S),      2, 0x263B}, // ☻
    {k(H),    k(T),      3, 0x2665}, // ♥
    {k(D),    k(M),      4, 0x2666}, // ♦
    {k(C),    k(B),      5, 0x2663}, // ♣
    {k(S),    k(P),      6, 0x2660}, // ♠
    {k(C),    k(R),      9, 0x25CB}, // ○
    {k(M),    k(S),     11, 0x2642}, // ♂
    {k(V),    k(S),     12, 0x2640}, // ♀
    {k(E),    k(N),     13, 0x266A}, // ♪
    {k(E),    k(S),     14, 0x266B}, // ♫
    {k(S),    k(N),     15, 0x263C}, // ☼
    {k(D),    k(EXLM),  19, 0x203C}, // ‼
    {k(EQL),  k(EQL),   22, 0x25AC}, // ▬
    {k(MINS), k(LABK),  26, 0x2192}, // →
    {k(RABK), k(MINS),  27, 0x2190}, // ←
    {k(LABK), k(RABK),  29, 0x2194}, // ↔
    {k(F),    k(F),    131, 0x0192}, // ƒ
    {k(DOT),  k(DOT),  133, 0x2026}, // …
    {k(D),    k(D),    135, 0x2021}, // ‡
    {k(CIRC), k(CIRC), 136, 0x02C6}, // ˆ
    {k(PERC), k(O),    137, 0x2030}, // ‰
    {k(V),    s(S),    138, 0x0160}, // Š
    {s(O),    s(E),    140, 0x0152}, // Œ
    {k(V),    s(Z),    142, 0x017D}, // Ž
    {k(T),    k(M),    153, 0x2122}, // ™
    {k(V),    k(S),    154, 0x0161}, // š
    {k(O),    k(E),    156, 0x0153}, // œ
    {k(V),    k(Z),    158, 0x017E}, // ž
    {k(N),    k(B),    160, 0x00A0}, // nbsp
    {k(EXLM), k(EXLM), 161, 0x00A1}, // ¡
    {k(DQUO), k(DQUO), 168, 0x00A8}, // ¨
    {k(LABK), k(LABK), 171, 0x00AB}, // «
    {k(MINS), k(COMM), 172, 0x00AC}, // ¬
    {k(O),    k(O),    176, 0x00B0}, // °
    {k(PLUS), k(MINS), 177, 0x00B1}, // ±
    {k(P),    k(EXLM), 182, 0x00B6}, // ¶
    {k(COMM), k(COMM), 184, 0x00B8}, // ¸
    {k(RABK), k(RABK), 187, 0x00BB}, // »
    {k(1),    k(4),    188, 0x00BC}, // ¼
    {k(1),    k(2),    189, 0x00BD}, // ½
    {k(3),    k(4),    190, 0x00BE}, // ¾
    {k(QUES), k(QUES), 191, 0x00BF}, // ¿
    {s(A),    s(E),    198, 0x00C6}, // Æ
    {s(C),    k(COMM), 199, 0x00C7}, // Ç
    {s(D),    s(H),    208, 0x00D0}, // Ð
    {k(X),    k(X),    215, 0x00D7}, // ×
    {s(T),    s(H),    222, 0x00DE}, // Þ
    {k(S),    k(S),    223, 0x00DF}, // ß
    {k(D),    k(H),    240, 0x00F0}, // ð
    {k(T),    k(H),    254, 0x00FE}  // þ
};

/**
 * \brief Mapping of two-key combinations that may be entered in any order
 * Meaning that also the reversed order needs to be considered.
 */
FCONST two_key_mapping_t any_order_combinations[] = {
    {k(R),    k(P),     16, 0x25BA}, // ►
    {k(L),    k(P),     17, 0x25C4}, // ◄
    {k(U),    k(D),     18, 0x2195}, // ↕
    {k(PIPE), k(B),     23, 0x21A8}, // ↨
    {k(PIPE), k(CIRC),  24, 0x2195}, // ↑
    {k(PIPE), k(V),     25, 0x2193}, // ↓
    {k(U),    k(P),     30, 0x25B2}, // ▲
    {k(D),    k(P),     31, 0x25BC}, // ▼
    {k(C),    k(EQL),  128, 0x20AC}, // €
    {k(COMM), k(QUOT), 130, 0x201A}, // ‚
    {k(COMM), k(DQUO), 132, 0x201E}, // „
    {k(S),    k(D),    134, 0x2020}, // †
    {k(DOT),  k(LABK), 139, 0x2039}, // ‹
    {k(LABK), k(QUOT), 145, 0x2018}, // ‘
    {k(RABK), k(QUOT), 146, 0x2019}, // ’
    {k(LABK), k(DQUO), 147, 0x201C}, // “
    {k(RABK), k(DQUO), 148, 0x201D}, // ”
    {k(DOT),  k(EQL),  149, 0x2022}, // •
    {k(MINS), k(DOT),  150, 0x2013}, // –
    {k(MINS), k(UNDS), 151, 0x2014}, // —
    {k(CIRC), k(TILD), 152, 0x02DC}, // ˜
    {k(DOT),  k(RABK), 155, 0x203A}, // ›
    {k(COLN), s(Y),    159, 0x0178}, // Ÿ
    {k(DQUO), s(Y),    159, 0x0178}, // Ÿ
    {k(C),    k(SLSH), 162, 0x00A2}, // ¢
    {k(L),    k(MINS), 163, 0x00A3}, // £
    {k(X),    k(O),    164, 0x00A4}, // ¤
    {k(Y),    k(EQL),  165, 0x00A5}, // ¥
    {k(EXLM), k(CIRC), 166, 0x00A6}, // ¦
    {k(S),    k(O),    167, 0x00A7}, // §
    {k(CIRC), k(COLN), 168, 0x00A8}, // ¨
    {k(O),    k(C),    169, 0x00A9}, // ©
    {k(A),    k(UNDS), 170, 0x00AA}, // ª
    {k(MINS), KC_SPC,  173, 0x00AD}, // shy
    {k(O),    k(R),    174, 0x00AE}, // ®
    {k(CIRC), k(MINS), 175, 0x00AF}, // ¯
    {k(CIRC), k(2),    178, 0x00B2}, // ²
    {k(CIRC), K(3),    179, 0x00B3}, // ³
    {k(QUOT), KC_SPC,  180, 0x00B4}, // ´
    {k(SLSH), k(U),    181, 0x00B5}, // μ
    {k(DOT),  k(MINS), 183, 0x00B7}, // ·
    {k(CIRC), k(1),    185, 0x00B9}, // ¹
    {k(O),    k(UNDS), 186, 0x00BA}, // º
    {k(GRV),  s(A),    192, 0x00C0}, // À
    {k(QUOT), s(A),    193, 0x00C1}, // Á
    {k(CIRC), s(A),    194, 0x00C2}, // Â
    {k(TILD), s(A),    195, 0x00C3}, // Ã
    {k(COLN), s(A),    196, 0x00C4}, // Ä
    {k(DQUO), s(A),    196, 0x00C4}, // Ä
    {k(ASTR), s(A),    197, 0x00C5}, // Å
    {k(GRV),  s(E),    200, 0x00C8}, // È
    {k(QUOT), s(E),    201, 0x00C9}, // É
    {k(CIRC), s(E),    202, 0x00CA}, // Ê
    {k(COLN), s(E),    203, 0x00CB}, // Ë
    {k(DQUO), s(E),    203, 0x00CB}, // Ë
    {k(GRV),  s(I),    204, 0x00CC}, // Ì
    {k(QUOT), s(I),    205, 0x00CD}, // Í
    {k(CIRC), s(I),    206, 0x00CE}, // Î
    {k(COLN), s(I),    207, 0x00CF}, // Ï
    {k(DQUO), s(I),    207, 0x00CF}, // Ï
    {k(TILD), s(N),    209, 0x00D1}, // Ñ
    {k(GRV),  s(O),    210, 0x00D2}, // Ò
    {k(QUOT), s(O),    211, 0x00D3}, // Ó
    {k(CIRC), s(O),    212, 0x00D4}, // Ô
    {k(TILD), s(O),    213, 0x00D5}, // Õ
    {k(COLN), s(O),    214, 0x00D6}, // Ö
    {k(DQUO), s(O),    214, 0x00D6}, // Ö
    {s(O),    k(SLSH), 216, 0x00D8}, // Ø
    {k(GRV),  s(U),    217, 0x00D9}, // Ù
    {k(QUOT), s(U),    218, 0x00DA}, // Ú
    {k(CIRC), s(U),    219, 0x00DB}, // Û
    {k(COLN), s(U),    220, 0x00DC}, // Ü
    {k(DQUO), s(U),    220, 0x00DC}, // Ü
    {k(QUOT), s(Y),    221, 0x00DD}, // Ý
    {k(GRV),  k(A),    224, 0x00E0}, // à
    {k(QUOT), k(A),    225, 0x00E1}, // á
    {k(CIRC), k(A),    226, 0x00E2}, // â
    {k(TILD), k(A),    227, 0x00E3}, // ã
    {k(COLN), k(A),    228, 0x00E4}, // ä
    {k(DQUO), k(A),    228, 0x00E4}, // ä
    {k(ASTR), k(A),    229, 0x00E5}, // å
    {k(A),    k(E),    230, 0x00E6}, // æ
    {k(C),    k(COMM), 231, 0x00E7}, // ç
    {k(GRV),  k(E),    232, 0x00E8}, // è
    {k(QUOT), k(E),    233, 0x00E9}, // é
    {k(CIRC), k(E),    234, 0x00EA}, // ê
    {k(COLN), k(E),    235, 0x00EB}, // ë
    {k(DQUO), k(E),    235, 0x00EB}, // ë
    {k(GRV),  k(I),    236, 0x00EC}, // ì
    {k(QUOT), k(I),    237, 0x00ED}, // í
    {k(CIRC), k(I),    238, 0x00EE}, // î
    {k(COLN), k(I),    239, 0x00EF}, // ï
    {k(DQUO), k(I),    239, 0x00EF}, // ï
    {k(TILD), k(N),    241, 0x00F1}, // ñ
    {k(GRV),  k(O),    242, 0x00F2}, // ò
    {k(QUOT), k(O),    243, 0x00F3}, // ó
    {k(CIRC), k(O),    244, 0x00F4}, // ô
    {k(TILD), k(O),    245, 0x00F5}, // õ
    {k(COLN), k(O),    246, 0x00F6}, // ö
    {k(DQUO), k(O),    246, 0x00F6}, // ö
    {k(COLN), k(MINS), 247, 0x00F7}, // ÷
    {k(SLSH), k(O),    248, 0x00F8}, // ø
    {k(GRV),  k(U),    249, 0x00F9}, // ù
    {k(QUOT), k(U),    250, 0x00FA}, // ú
    {k(CIRC), k(U),    251, 0x00FB}, // û
    {k(COLN), k(U),    252, 0x00FC}, // ü
    {k(DQUO), k(U),    252, 0x00FC}, // ü
    {k(QUOT), k(Y),    253, 0x00FD}, // ý
    {k(COLN), k(Y),    255, 0x00FF}, // ÿ
    {k(DQUO), k(Y),    255, 0x00FF}, // ÿ
};

void keyboard_gre_init_user(void) {
    debug_config.enable = true;
    debug_config.matrix = true;
    debug_config.keyboard = true;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // apply shift
            break;

        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case k(UNDS):
            break; // unshifted

        default:
            return false; // deactivate Caps Word.
    }
    return true;
}

// .
