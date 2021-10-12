#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

#include "list.h"

int main()
{
  list_t *list = list_make(10);

  for (int i = 0; i < 40; i++)
  {
    list_add(list, i);
  }
  
  for (int i = 0; i < list->count; i++)
  {
    // printf("%d ", list->arr[i]);
    printf("%d ", list_at(list, i));
  }
  printf("\n");

  printf("%d\n", list_at(list, 4));
  list_remove(list, 4);
  printf("%d\n", list_at(list, 4));

  list_free(list);
  /*
  int *arr = malloc(10 * sizeof(int));
  // int *arr = calloc(10, sizeof(int));
  
  if (arr != NULL)
  {
    for (int i = 0; i < 10; i++)
    {
      arr[i] = i * 10;
    }

    // arr = realloc(arr, 20 * sizeof(int));

    printf("%d %d\n", arr[0], arr[1]);

    free(arr);
    arr = NULL;
  }
  */
}
