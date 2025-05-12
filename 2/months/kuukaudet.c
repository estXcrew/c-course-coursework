#include <stdio.h>
#include <stdint.h>
#include "kuukaudet.h"
#include <ctype.h>
const char *KK_NIMET[KK_LKM] = {
  "tammikuu",
  "helmikuu",
  "maaliskuu",
  "huhtikuu",
  "toukokuu",
  "kesäkuu",
  "heinäkuu",
  "elokuu",
  "syyskuu",
  "lokakuu",
  "marraskuu",
  "joulukuu"
};

const char KK_PAIVAT[2][KK_LKM] = {
  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


/*
int main() 
{
  printf("Helmikuu 2016: %d päivää\n", kkPituus("Helmikuu", 2016));
  printf("Helmikuu 2100: %d päivää\n", kkPituus("helmikuu", 2100));
  printf("Helmi kuu 2100: %d päivää\n", kkPituus("helmi kuu", 2100));
  return 0;
}*/

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