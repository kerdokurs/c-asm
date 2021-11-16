#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "magasin.h"

#define STACK_SIZE 300

typedef struct
{
  int8_t *arr;
  size_t amt_el;
} magasin_impl_t;

static magasin_error_t mag_push(magasin_t *mag, int8_t val)
{
  magasin_impl_t *impl = /* (magasin_impl_t *) */mag->impl;

  if (impl->amt_el >= STACK_SIZE)
  {
    return MAG_OVERFLOW;
  }

  impl->arr[impl->amt_el++] = val;

  return MAG_OK;
}

static magasin_error_t mag_peek(magasin_t *mag, int8_t *out)
{
  magasin_impl_t *impl = mag->impl;

  if (impl->amt_el <= 0)
  {
    return MAG_UNDERFLOW;
  }

  *out = impl->arr[impl->amt_el - 1];

  return MAG_OK;
}

static magasin_error_t mag_pop(magasin_t *mag, int8_t *out)
{
  magasin_impl_t *impl = mag->impl;

  if (impl->amt_el <= 0)
  {
    return MAG_UNDERFLOW;
  }

  *out = impl->arr[--impl->amt_el];

  return MAG_OK;
}

static bool mag_is_empty(magasin_t *mag)
{
  return ((magasin_impl_t *) mag->impl)->amt_el == 0;
}

static void mag_print(magasin_t *mag)
{
  magasin_impl_t *impl = mag->impl;

  for (size_t i = 0; i < impl->amt_el; ++i)
  {
    printf("%d ", impl->arr[i]);
  }
  printf("\n");
}

static void mag_free(magasin_t *mag)
{
  if (mag == NULL)
  {
    return;
  }

  magasin_impl_t *impl = mag->impl;
  
  if (impl->arr != NULL)
  {
    free(impl->arr);
    impl->arr = NULL;
    impl->amt_el = 0;
  }

  free(mag->impl);
  free(mag);

  mag = NULL;
}

magasin_t *magasin_make(void)
{
  magasin_t *magasin = malloc(sizeof(magasin_t));

  magasin->push = mag_push;
  magasin->peek = mag_peek;
  magasin->pop = mag_pop;
  magasin->is_empty = mag_is_empty;
  magasin->print = mag_print;
  magasin->free = mag_free;
  
  magasin_impl_t *impl = malloc(sizeof(magasin_impl_t));
  impl->arr = malloc(STACK_SIZE * sizeof(int8_t));
  impl->amt_el = 0;

  magasin->impl = impl;

  return magasin;
}
