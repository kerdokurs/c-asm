#pragma once

#include <memory.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  size_t size;
  int count;
  char *arr;
} list_t;

/**
 * Loob uue listi ja tagastab selle viida
 * `initial_size` - listi algne suurus
 */
list_t *list_make(int initial_size);

/**
 * Kustutab (vabastab) listi
 * `list` - listi viit
 */
void list_free(list_t *list);

/**
 * Lisab elemendi `v` listi lõppu
 * `v` - element
 */
void list_add(list_t *list, char v);

/**
 * Eemaldab ja tagastab listist viimase elemendi
 */
char list_pop(list_t *list);

/**
 * Tagastab kohal `index` oleva elemendi
 */
char list_at(list_t *list, int index);

/**
 * Seab listis koale `index` väärtuse `value`
 */
void list_set(list *list, int index, char value);

/**
 * Eemaldab kohal `index` oleva elemendi
 */
void list_remove(list_t *list, int index);
