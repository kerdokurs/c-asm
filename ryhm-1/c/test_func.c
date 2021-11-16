#include <stdio.h>
#include <stdlib.h>

void test()
{
  printf("test\n");
}

int add(int x, int y)
{
  return x + y;
}

int main()
{
  int (* add_func)(int x, int y) = add;
  printf("%d\n", add_func(5, 1));
}
