#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "list.h"

int main()
{
  // int *arr = malloc(10 * sizeof(int));

  /*
  for (int i = 0; i < 10; i++)
  {
    arr[i] = i * i;
  }

  for (int i = 0; i < 10; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
  */

  // free(arr);

  list_t *list = list_make(10);

  for (int i = 0; i < 80; i++)
  {
    list_add(list, i);
  }

  while (!list_empty(list))
  {
    printf("%d ", list_pop(list));
  }
  printf("\n");

  list_free(list);
}

