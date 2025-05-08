#include "utf8.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

void utf8_encode(uint32_t *codes, unsigned char* utf8);
uint32_t find_msb_idx(uint32_t current_code);

int main(void)
{
  unsigned int codes[6] = {228, 49340, 49457, 12477, 12491, 12540};
  unsigned char utf8[5];
  int i = 0;

  for(i = 0; i < 6; ++i)
  {
    utf8_encode(codes[i], utf8);
    printf("%s\n", utf8);
  }

  return 0;
}

void utf8_encode(uint32_t *codes, unsigned char* utf8)
{
  int i;
  unsigned int current_code;
  unsigned int msb_idx;
  unsigned int nr_bytes;


  for(i=0; i<sizeof(codes); i++)
  {
    current_code = codes[i];
    msb_idx = find_msb_idx(current_code);
    nr_bytes = ((msb_idx / 8) & ~(0xFFu)) + 1u;
    
  }

}

uint32_t find_msb_idx(uint32_t current_code){
  int i;
  uint32_t retval;

  if(current_code == 0){
    return 0;
  }
  
  for(i=0; i<32; i++){
    if(current_code & 0b1){
      retval = i;
    }

    current_code = current_code >> 1U;
  }

  return retval;
}
