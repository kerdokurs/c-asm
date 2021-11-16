#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "test.h"
#include "magasin.h"

int main()
{
  magasin_t *mag = magasin_make();
  
  ASSERT("Uus magasin on tühi", mag->is_empty(mag));
  mag->push(mag, 10);
  ASSERT("Magasin pole tühi", !mag->is_empty(mag));

  int8_t x;
  ASSERT("Magasin peek töötab", mag->peek(mag, &x) == MAG_OK);
  ASSERT("Magasini pealmine element on õige", x == 10);
}
