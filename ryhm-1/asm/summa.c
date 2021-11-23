// summa.c

#include <stdio.h>

// deklareeri funktsioonip2is
// ja implementeeri funktsioon ASMis
// `summa`

int summa(int x, int y);

int main()
{
  int x = 10;
  int y = 20;
  int z = summa(x, y);
  printf("%d + %d = %d\n", x, y, z);
}
