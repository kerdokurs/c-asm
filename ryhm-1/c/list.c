#include "list.h"

list_t *list_make(int initial_size)
{
  list_t *list = malloc(sizeof(list_t));

  if (!list)
  {
    printf("Could not create list (memory allocation fault)\n");
    exit(-1);
  }

  list->count = 0;
  list->size = initial_size;
  list->arr = malloc(initial_size * sizeof(char));

  if (!list->arr)
  {
    printf("Could not create list (memory allocation fault)\n");
    exit(-1);
  }

  return list;
}

void list_free(list_t *list)
{
  free(list->arr);
  list->arr = NULL;
  free(list);
  list = NULL;
}

// `static` funktsioonid on nähtavad vaid siin failis
static void list_resize(list_t *list, int amt)
{
  printf("Resizing list\n");

  int bytes_to_alloc = amt * sizeof(char);

  // Suurendab massiivi ja kopeerime algse sisu ümber
  list->arr = realloc(list->arr, bytes_to_alloc);

  // Kas saime mälu?
  if (!list->arr)
  {
    printf("Could not (re)allocate more memory (%d bytes)\n", bytes_to_alloc);
    exit(-1);
  }

  list->size = amt;
}

void list_add(list_t *list, char value)
{
  if (list->count >= list->size)
  {
    list_resize(list, list->size * 2);
  }

  list->arr[list->count] = value;
  list->count++;
}

char list_pop(list_t *list)
{
  list->count--;
  char c = list->arr[list->count];

  if (list->count < list->size / 2)
  {
    list_resize(list, list->size / 2);
  }

  return c;
}

char list_at(list_t *list, int index)
{
  if (index >= 0 && index < list->count)
  {
    return list->arr[index];
  }

  printf("Index out or range\n");
  return 0;
}

void list_set(list_t *list, int index, char value)
{
  if (index >= 0 && index < list->count)
  {
    list->arr[index] = value;
  }

  printf("Index out or range\n");
}

void list_remove(list_t *list, int index)
{
  if (index >= 0 && index <= list->count)
  {
    for (int i = index + 1; i < list->count; i++)
    {
      list->arr[i - 1] = list->arr[i];
    }
    list->count--;

    if (list->count < list->size / 2)
    {
      list_resize(list, list->size / 2);
    }
  }
  else
  {
    printf("Index out of range\n");
  }
}
