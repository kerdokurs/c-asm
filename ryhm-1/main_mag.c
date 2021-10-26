#include <stdio.h>
#include <stdlib.h>

#include "magasin.h"

int main()
{
  magasin_t *magasin = magasin_make();
  magasin->push(magasin, 10);
  printf("%d\n", magasin->is_empty(magasin));
  int8_t x;
  magasin->pop(magasin, &x);
  printf("%d\n", magasin->is_empty(magasin));
  magasin_error_t err = magasin->pop(magasin, &x);
  printf("%d %d\n", x, err);

  printf("====================\n");
  magasin_t *magasin2 = magasin_make2();
  magasin2->print(magasin2);
}
