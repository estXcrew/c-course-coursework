#include <stdio.h>
#include <stdint.h>
#include "kuukaudet.h"
#include <ctype.h>

int karkausvuosi(int vuosiluku) {
  return (vuosiluku % 4 == 0 && vuosiluku % 100 != 0) || (vuosiluku % 400 == 0);
}

int vertaa_ilman_kirjainkokoa(const char *a, const char *b) {
  while (*a && *b) {
      if (tolower((unsigned char)*a) != tolower((unsigned char)*b)) {
          return 0;
      }
      a++;
      b++;
  }
  return *a == '\0' && *b == '\0';
}

char kkPituus(const char *kkNimi, int vuosiluku) {
  int i, onKarkaus;
  for (i = 0; i < KK_LKM; i++) {
      if (vertaa_ilman_kirjainkokoa(kkNimi, KK_NIMET[i])) {
          onKarkaus = karkausvuosi(vuosiluku);
          return KK_PAIVAT[onKarkaus][i];
      }
  }
  return -1;
}