#pragma once

#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct
{
  size_t size;
  int count;
  char *arr;
} list_t;

list_t *list_make(size_t initial_size);

void list_free(list_t *list);

void list_add(list_t *list, char value);

char list_pop(list_t *list);

char list_at(list_t *list, int index);

void list_remove(list_t *list, int index);

void list_set(list_t *list, int index, char value);

bool list_empty(list_t *list);
