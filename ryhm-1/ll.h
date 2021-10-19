#pragma once

#include <memory.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  struct ll_node_t *next;
  char val;
} ll_node_t;

typedef struct
{
  ll_node_t *head;
  size_t size;
} ll_t;

ll_t *ll_make();

void ll_free(ll_t *ll);

void ll_add_node(ll_t *ll, char val);

char ll_at(ll_t *ll, int index);

void ll_set(ll_t *ll, int index, char val);

void ll_remove(ll_t *ll, int index);

char ll_pop(ll_t *ll);

// ll_set(ll, 4, 'c');
// idx 0    1    2    3    4
//     o -> o -> o -> o -> o
// val 1    2    3    0    c
// ptr                     ^
