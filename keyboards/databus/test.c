// Created/amended by OleVoip 2024.
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef __FLASH
#define __flash
#endif

#define N 256
uint8_t vals[N];
uint8_t iVals[N];

void printvals(){
  uint8_t i = 0;
  do { 
    printf("%02x", vals[iVals[i]]);
    printf((i & 0xF) == 0xF ? "\n" : "-");
  } while(i++ < N-1);
  printf("\n");
}

__flash const uint8_t gaps[] = {1, 4, 10, 23, 57, 132};

void sortvals(){
  uint8_t iGap = sizeof(gaps) / sizeof(gaps[0]);
  while (iGap--) {
    uint8_t gap = gaps[iGap];
    if (gap > N-1) continue;

    uint8_t iFirst = gap;
    uint8_t iSecond = 0;
    uint8_t iSecondLimit = N - gap;
    while (iSecond < iSecondLimit) {
      uint8_t iHole = iFirst++;
      uint8_t iNext = iSecond++;

      uint8_t iVal = iVals[iHole];
      uint8_t iValNext = iVals[iNext];
      uint8_t val = vals[iVal];

      while (vals[iValNext] > val) {
	iVals[iHole] = iValNext;
	iHole = iNext;
	if (iHole < gap) break;
	iNext -= gap;
	iValNext = iVals[iNext];
      }

      iVals[iHole] = iVal;
    }
  }
}

int main(void) {
  uint8_t i = N - 1;
  do {
    iVals[i] = i;
    vals[i] = rand();
  } while(i--);
  printvals();
  sortvals();
  printvals();
  i = 0;
  do { 
    printf("%02x", iVals[i]);
    printf((i & 0xF) == 0xF ? "\n" : "-");
  } while(i++ < N-1);
  printf("\n");
}
