#include <stdio.h>

// Kirjuta see assembleris
void summa(int *x, int *y, int n);
// x[i] += y[i] for all i < n

int main()
{
  int n = 6;
  int x[] = {1, 2, 3, 4, 5, 6};
  int y[] = {1, 2, 3, 4, 5, 6};
  summa(x, y, n);
  for (int i = 0; i < n; i++)
  {
    printf("%d ", x[i]);
  }
  printf("\n"); // 2 4 6 8 10
}
