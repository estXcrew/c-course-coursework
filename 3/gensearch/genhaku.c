#include <stddef.h>
#include <stdio.h>
#include "genhaku.h"

#ifdef LIVE
int main(void)
{
  int ix[10] = {4, 1, 0, 8, 2, 9, 0, 8, 2, 9};
  int iy[4] = {0, 8, 2, 9};
  int iz[4] = {0, 9, 2, 8};
  short sx[10] = {4, 1, 0, 8, 2, 9, 0, 8, 2, 9};
  short sy[4] = {0, 8, 2, 9};
  short sz[4] = {0, 9, 2, 9};
  typedef unsigned long ulong;
  printf("%lu %lu\n", (ulong) etsi(ix, 10, iy, 4, sizeof(int)),
                      (ulong) etsi(ix, 10, iz, 4, sizeof(int)));
  printf("%lu %lu\n", (ulong) etsi(sx, 10, sy, 4, sizeof(short)),
                      (ulong) etsi(sx, 10, sz, 4, sizeof(short)));
  printf("%lu\n", (ulong) etsi("language", 8, "age", 3, sizeof(char)));
  return 0;
}

#endif

int check_match(char* target_start, char* query, size_t nr_bytes)
{
    size_t i;
    for(i=0; i<nr_bytes; i++)
    {
        if(*(query+i) != *(target_start+i))
        {
            /*printf("partial match only, cancel\r\n");*/
            return 0;
        }
    }
    /*printf("found match!\r\n");*/
    return 1;
}


size_t etsi(void *mista, size_t n, void *mita, size_t m, size_t koko) {
    char* i;
    char* target_ptr = (char*)mita;
    size_t word_ctr = 0;
    size_t loc_ctr = 0;

    for(i=(char*)mista; i<((char*)mista+(koko*n)); i++)
    {
        if((*i) == (*target_ptr)) {
            if(check_match(i, target_ptr, koko*m)){
                break;
            }
        }

        loc_ctr++;
        
        if(loc_ctr == koko){
            word_ctr++;
            loc_ctr=0;
        }
    }

    /*printf("returning idx %ld\n", word_ctr);*/

    return word_ctr;
}
