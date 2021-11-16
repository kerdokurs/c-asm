#include <stdio.h>
#include <stddef.h>

void func(int *x, int *y)
{
  *x = 10;
  *y = 60;
}

void func1(int x, int y)
{
  x = 70;
  y = 100;
}

typedef struct
{
  int x;
} demo_t;

void print_demo(demo_t *demo)
{
  printf("%p\n", demo);
  printf("%d\n", demo->x);
  demo->x = 100;
}

void print_demo1(demo_t demo)
{
  printf("%p\n", &demo);
  printf("%d\n", demo.x);
  demo.x = 200;
}

void add(int *x, int *y, int *z)
{
  // EI TOHI: z = x + y;
  *z = *x + *y;
}

// NB! size_t jaoks on vaja stddef.h
/* void print_array(int *arr, size_t n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d\n", arr[i]);
  }
} */

typedef struct
{
  // massiivi sisu
  int *arr;
  // massiivi pikkus
  size_t size;
} int_array_t;

void print_array(int_array_t *int_array)
{
  int_array->size = 10;
  for (int i = 0; i < int_array->size; i++)
  {
    printf("%d\n", int_array->arr[i]);
  }
}

int main()
{
  int x = 50;
  int y = 40;
  printf("%d, %d\n", x, y);
  func(&x, &y);
  printf("%d, %d\n", x, y);
  func1(x, y);
  printf("%d, %d\n", x, y);

  demo_t demo;
  demo.x = 800;
  printf("%p\n", &demo);
  print_demo(&demo);
  printf("%d\n", demo.x);
  print_demo1(demo);
  printf("%d\n", demo.x);

  int z = 0;
  add(&x, &y, &z);
  // z peaks olema 70
  printf("z = %d\n", z);

  int arr[3];
  arr[0] = x;
  arr[1] = y;
  arr[2] = z;
  // printf("%d, %d, %d\n", arr[0], arr[1], arr[2]);
  // printf("%d, %d, %d\n", *(arr), *(arr + 1), *(arr + 2));
  int_array_t int_array;
  int_array.arr = arr;
  int_array.size = 3;
  print_array(&int_array);

  const int xx = 20;
  const int x2 = 50;
  int x3 = 60;
  const int *yy = &xx;
  yy = &x2;
  yy = &x3;
  // *yy = 20;

  int aa = 10;   // 4 baiti
  long bb = 20;  // 8 baiti
  char cc = 'c'; // 1 bait
  void *ptr = NULL; // = NULL; nullpointer
  // printf("%d\n", *((int *)ptr));

  ptr = &aa;
  printf("%d\n", *((int *)ptr));
  ptr = &bb;
  printf("%ld\n", *((long *)ptr));
  ptr = &cc;
  printf("%d, %d\n", *((char *)ptr), 'c');
  /*
  | aa | bb | cc | ptr | ...
  | 4  | 8  | 1  | ...
  */

  int *m[3];
  m[0] = &x;
  m[1] = &y;
  m[2] = &z;

  // prindib x, y ja z muutujate mäluaadressid
  printf("%p, %p, %p\n", m[0], m[1], m[2]);

  // prindib x, y ja z muutujate väärtused ilma x, y ja z otseselt kasutamata
  // need kaks on ekvivalentsed
  printf("%d, %d, %d\n", *m[0], *m[1], *m[2]);
  printf("%d, %d, %d\n", **m, **(m + 1), **(m + 2));

  return 0;
}
