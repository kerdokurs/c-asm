#include "list.h"

list_t *list_make(size_t initial_size)
{
  list_t *list = malloc(sizeof(list_t));
  list->count = 0;
  list->size = initial_size;
  list->arr = malloc(initial_size * sizeof(char));

  return list;
}

void list_free(list_t *list)
{
  free(list->arr);
  list->arr = NULL;
  free(list);
  list = NULL;
}

static void list_resize(list_t *list, size_t size)
{
  printf("Resizing list\n");

  int bytes_to_alloc = size * sizeof(char);

  list->arr = realloc(list->arr, bytes_to_alloc);

  if (list->arr == NULL)
  {
    printf("Could not (re)allocate more memory (%d bytes)\n", bytes_to_alloc);
    exit(-1);
  }

  list->size = size;
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
  if (list->count > 0)
  {
    list->count--;
    char c = list->arr[list->count];

    if (list->count < list->size / 2)
    {
      list_resize(list, list->size / 2);
    }

    return c;
  }

  printf("No elements left\n");
}

char list_at(list_t *list, int index)
{
    return list->arr[index];

  printf("Index out of range\n");
  return 0;
}

void list_remove(list_t *list, int index)
{
  if (index >= 0 && index < list->count)
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

    return;
  }

  printf("Index out of range\n");
}

void list_set(list_t *list, int index, char value)
{
  if (index > list->size)
  {
    list_resize(list, index + 1);
  }

  list->arr[index] = value;
  // TODO: how to update count?
}

bool list_empty(list_t *list)
{
  return list->count == 0;
}
