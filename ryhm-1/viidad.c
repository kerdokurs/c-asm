#include <stdio.h>
#include <stddef.h>

typedef struct demo_t 
{
  int x;
  struct demo_t *demo;
} demo_t;

/**
 * Paneb mäluaadressidel x ja y olevate muutujate summa mäluaadressil z olevasse muutujasse.
 */
void func(int *x, int *y, int *z)
{
  // Mida mitte teha: z = x + y!
  *z = *x + *y;
}

void print_demo(demo_t *demo)
{
  printf("%d\n", demo->x);
}

// NB! size_t jaoks importida stddef.h (või mõni muu päisefail, kus see defineeritud)
/* void print_array(int *arr, size_t n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d\n", arr[i]);
    printf("%d\n", *(arr + i));
  }
} */

typedef struct
{
  // massiivi sisu
  int *arr;
  // massiivi pikkus
  size_t size;
} int_array_t;

/**
 * Prindib int_array_t sisu kahel eri viisil
 */
void print_array(int_array_t *int_array)
{
  for (int i = 0; i < int_array->size; i++)
  {
    printf("%d\n", int_array->arr[i]);
    printf("%d\n", *(int_array->arr + i));
  }
}

typedef struct
{
  int x;
} s_t;

void test_s(s_t st)
{
  printf("%p\n", &st);
  st.x = 20;
}

void test_s1(s_t *st)
{
  printf("%p\n", st);
  st->x = 20;
}

int main()
{
  demo_t demo;
  demo.x = 5;
  print_demo(&demo);

  // mis saab siis, kui kaasa anda struct mitte tema viit??
  s_t st;
  st.x = 10;
  printf("%d\n", st.x);
  test_s(st);
  printf("%d\n", st.x);
  test_s1(&st);
  printf("%d\n", st.x);
  printf("%p\n", &st);

  // aga mis on const *??
  const int xx = 5;
  const int x2 = 6;
  const int *yy = &xx;
  yy = &x2;

  // ja mis on void *??
  int aa = 0xaa00;
  long bb = 10;
  char cc = 'c';
  void *ptr = 0; // = NULL
  ptr = &aa;
  printf("%d\n", *((int *)ptr));
  ptr = &bb;
  printf("%ld\n", *((long *)ptr));
  ptr = &cc;
  printf("%d\n", cc);
  printf("%c\n", (*((char *)ptr) & 0xff));
  /*
    | aa | bb | cc | muu sodi
    | 4  | 8  | 1  | ... 
  */

  int x = 2;
  int y = 4;
  int z = 0;

  int a[3];
  a[0] = x;
  a[1] = y;
  a[2] = z;

  int_array_t int_array;
  int_array.arr = a;
  int_array.size = 3;
  print_array(&int_array);

  // Viitade viit
  int *arr[3];
  arr[0] = &x;
  arr[1] = &y;
  arr[2] = &z;

  // Need kaks on samaväärsed
  printf("%d, %d, %d\n", **arr, **(arr + 1), **(arr + 2));
  printf("%d, %d, %d\n", *arr[0], *arr[1], *arr[2]);

  func(&x, &y, &z);

  // z peaks olema 6
  printf("z = %d\n", z);

  return 0;
}
