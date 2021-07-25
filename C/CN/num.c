#include <stdio.h>
int main()
{
  struct pkt
  {
    int c1;
    int c2;
    int c3;
  };
  struct pkt p1;
  printf("First number\n");
    scanf("%d", &p1.c1);

  printf("Second number\n");
    scanf("%d", &p1.c2);

  printf("Third number\n");
    scanf("%d", &p1.c3);

    printf("%d %d %d",p1.c1,p1.c2,p1.c3);
  return 0;
}