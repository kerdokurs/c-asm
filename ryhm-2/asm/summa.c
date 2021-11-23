#include <stdio.h>

int summa(int x, int y);

int main()
{
  int x = 10;
  int y = 20;
  int z = summa(x, y);
  printf("%d + %d = %d\n", x, y, z);
}
