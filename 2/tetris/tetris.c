
#include "tetris.h"
#include <stdio.h>
#ifdef LIVE
/* Alla määritetään 2-ulotteinen 20x10-kokoinen staattinen merkkitaulukko,
   jossa täynnä olevat ruudut on merkitty merkillä 'x'. Kukin 10-alkioinen
   alitaulukko alustetaan merkkijonolla (jonka loppumerkki leikkautuu pois). */
char ruudukko[20][10] = {"          ",  /* Rivi 0: ylin rivi.                */
                         "  x   x   ",  /* Rivi 1: toiseksi ylin rivi.       */
                         " xx   xxx ",  /* ...ja niin edelleen...            */
                         "xxx xxxxxx",
                         "xxxxxxxxxx",  /* Rivi 4: täynnä.                   */
                         "xxxxxxxxxx",  /* Rivi 5: täynnä.                   */
                         "xxxxxx xxx",
                         "xxxxxxx xx",
                         "x xxxxxxxx",
                         "xxx xxx xx",
                         "xxxxxx xxx",
                         "x xx xxx x",
                         "xxxxxxxxx ",
                         "xxx xxx xx",
                         "xxxxx xx x",
                         " xxxxxxxxx",
                         "xxx xxx xx",
                         "x xxxx xxx",
                         "xxxxx xxxx",  /* Rivi 18: toiseksi alin rivi.      */
                         "xxxxxxxx x"}; /* Rivi 19: alin rivi.               */



int main(void)
{
  int i = 0;
  paivita(ruudukko);       /* Poistetaan tyhjät rivit. */
  for(i = 0; i < 20; ++i)  /* Tulostetaan ruudukko.    */
  {
    printf("%.10s\n", ruudukko[i]); /* Tulostetaan 1 rivi eli 10 merkkiä. */
  }
  return 0;
}

#endif

/* board top idx0 */
/* board bottom idx19 */
void paivita(char ruudukko[20][10])
{
    int cur_row; /* index of iterating */
    int cp_row;
    int cur_char; /* index of char in row */
    char is_full = 1; /* "bool" value is the row full or not */
    
    /* start from bottom-1, cur_row check will add +1 */
    for(cur_row=18; cur_row>=0;cur_row--)
    {

        /* if check from previous round was full, it means I could have copied a full row down, we need to check again */
        if(is_full){
            cur_row+=1;
        }

        /* is_full is 1 by default unless otherwise detected in the check */
        is_full = 1;

        for(cur_char=0; cur_char < 10; cur_char++){

            if(ruudukko[cur_row][cur_char] == ' '){
                is_full = 0;
            }
        }

        if(is_full) {
            /* copy array down top to bottom to this index, then clear top row*/

            for(cp_row=cur_row; cp_row>0; cp_row--)
            {
                for(cur_char=0; cur_char < 10; cur_char++){
                    ruudukko[cp_row][cur_char] = ruudukko[cp_row-1][cur_char];
                }
            }
            
            for(cur_char=0; cur_char < 10; cur_char++){
                ruudukko[0][cur_char] = ' ';
            }

        }
    }
}
