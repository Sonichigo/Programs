#include <stdio.h>
#include <inttypes.h>
int main ()
{
  unsigned int x = 0x76543210;
  char *c = (char*) &x;
 
  printf ("*c is: 0x%x\n", *c);
  if (*c == 0x10)
  {
    printf ("Underlying architecture is little endian. \n");
  }
  else
  {
     printf ("Underlying architecture is big endian. \n");
  }
 uint32_t be = __builtin_bswap32(x);

    printf("Little-endian: 0x%"PRIx32"\n", x);
    printf("Big-endian:    0x%"PRIx32"\n", be);
  return 0;
}