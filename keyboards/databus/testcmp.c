#include <stdio.h>
#include <stdint.h>

#define ARRAY_LEN(a) (sizeof(a) / sizeof((a)[0]))

typedef struct AltMapping {
  uint8_t ac;
  uint16_t uc;
} AltMapping;

const uint16_t
  U___ = ' ',  // empty
  ucC0range[] = { // cp437/850 graphemes instead of C0 controls
    0x00, u'☺', u'☻', u'♥', u'♦', u'♣', u'♠', u'•',
    u'◘', u'○', u'◙', u'♂', u'♀', u'♪', u'♫', u'☼',
    u'►', u'◄', u'↕', u'‼', u'¶', u'§', u'▬', u'↨',
    u'↑', u'↓', u'→', u'←', u'∟', u'↔', u'▲', u'▼'},
  ucC1range[] = { // cp1252 graphemes instead of C1 controls
    u'€', u'ƒ', u'‚', U___, u'„', u'…', u'†', u'‡',
    u'ˆ', u'‰', u'Š', u'‹', u'Œ', U___, u'Ž', U___,
    U___, u'‘', u'’', u'“', u'”', u'•', u'–', u'—',
    u'˜', u'™', u'š', u'›', u'œ', U___, u'ž', u'Ÿ'};

typedef enum { // only needed for unicodes beyond latin1, otherwise 'x'/u'x'
  C_NL, C_SM, C_BF, C_CH, C_CD, C_CC, C_CS, C_BT,
  C_IB, C_WC, C_IC, C_ML, C_FM, C_EN, C_BN, C_SN,
  C_PR, C_PL, C_UD, C_DX, C_PC, C_SC, C_BR, C_AB,
  C_AU, C_AD, C_AR, C_AL, C_RA, C_LR, C_PU, C_PD,
  C_DI = '0', C_FH, C_DU, C_UB, C_LB, C_FB, C_LS, C_MS, C_DS, C_SQ,
  C_HS = 'A',
  C_hz, C_vt, C_dr, C_dl, C_ur, C_ul, C_vr, C_vl, C_dh, C_uh, C_vh,
  C_HZ, C_VT, C_DR, C_DL, C_UR, C_UL, C_VR, C_VL, C_DH, C_UH, C_VH,
  C_EU, C_81, C_l9, C_83, C_L9, C_ES, C_DG, C_DD,
  C_CM, C_PM, C_SH, C_QL, C_OE, C_8d, C_ZH, C_8f,
  C_90, C_lq, C_rq, C_LQ, C_RQ, C_95, C_ND, C_MD,
  C_ST, C_TM, C_sh, C_QR, C_oe, C_9d, C_zh, C_YU,
  C_NB = 0xA0,
  C_HY = 0xAD
} compose_t;

const AltMapping
  numRangeMap[10] = { // 0x30…39
    {0xd5, u'ı'}, // 0 DI latin small letter dotless i
    {0x9f, u'ƒ'}, // 1 FH latin small letter f with hook
    {0xf2, u'‗'}, // 2 DU double low line
    {0xdf, u'▀'}, // 3 UB upper half block
    {0xdc, u'▄'}, // 4 LB lower half block
    {0xdb, u'█'}, // 5 FB full block
    {0xb0, u'░'}, // 6 LS light shade
    {0xb1, u'▒'}, // 7 MS medium shade
    {0xb2, u'▓'}, // 8 DS dark shade
    {0xfe, u'■'}},// 9 SQ black square
  capsRangeMap[23] = { // 0x41…57 (58, 59, 5A unassigned)
    {0x7f, u'⌂'}, // A HS house
    {0xc4, u'─'}, // B hz box drawings light horizontal
    {0xb3, u'│'}, // C vt box drawings light vertical
    {0xda, u'┌'}, // D dr box drawings light down and right
    {0xbf, u'┐'}, // E dl box drawings light down and left
    {0xc0, u'└'}, // F ur box drawings light up and right
    {0xd9, u'┘'}, // G ul box drawings light up and left
    {0xc3, u'├'}, // H vr box drawings light vertical and right
    {0xb4, u'┤'}, // I vl box drawings light vertical and left
    {0xc2, u'┬'}, // J dh box drawings light down and horizontal
    {0xc1, u'┴'}, // K uh box drawings light up and horizontal
    {0xc5, u'┼'}, // L vh box drawings light vertical and horizontal
    {0xcd, u'═'}, // M HZ box drawings double horizontal
    {0xba, u'║'}, // N VT box drawings double vertical
    {0xc9, u'╔'}, // O DR box drawings double down and right
    {0xbb, u'╗'}, // P DL box drawings double down and left
    {0xc8, u'╚'}, // Q UR box drawings double up and right
    {0xbc, u'╝'}, // R UL box drawings double up and left
    {0xcc, u'╠'}, // S VR box drawings double vertical and right
    {0xb9, u'╣'}, // T VL box drawings double vertical and left
    {0xcb, u'╦'}, // U DH box drawings double down and horizontal
    {0xca, u'╩'}, // V UH box drawings double up and horizontal
    {0xce, u'╬'}};// W VH box drawings double vertical and horizontal

int main() {
  for(uint16_t c = 0; c < 0x100; c++){
    uint16_t wc;
    if (c == 0) {
      wc = U___;
    } else if (c < 0x20){
      wc = ucC0range[c];
    } else if (c >= 0x30 && c < 0x3A){
      wc = numRangeMap[c-0x30].uc;
    } else if (c >= 0x41 && c < 0x57){
      wc = capsRangeMap[c-0x41].uc;
    } else if (c >= 0x80 && c < 0xA0){
      wc = ucC1range[c & 0x1F];
    } else {
      wc = c;
    }
    if (wc <= 0x7F) {
      putchar(wc);
    } else if (wc <= 0x7FF) {
      putchar(0xC0 | (wc >> 6));
      putchar(0x80 | (wc & 0x3F));
    } else {
      putchar(0xE0 | (wc >> 12));
      putchar(0x80 | ((wc >> 6) & 0x3F));
      putchar(0x80 | (wc & 0x3F));
    }
    if(c % 0x20 == 0x1F){
      putchar('\n');
    }
  }
}
