#include <stdlib.h>
#include <stdio.h>

#include "queue.h"

queue_t *queue_make(void)
{
  queue_t *queue = malloc(sizeof(queue_t));
  
  return queue;
}

static void queue_list_free(queue_list_t *node)
{
  if (node == NULL)
  {
    return;
  }

  queue_list_free(node->next);
  free(node);
}

void queue_free(queue_t *queue)
{
  queue_list_free(queue->head);
  free(queue);
  queue = NULL;
}

void queue_push(queue_t *queue, const char c)
{
  queue_list_t *node = queue->head;

  if (node == NULL)
  {
    node = malloc(sizeof(queue_list_t));
    node->c = c;
    queue->head = node;
    return;
  }

  while (node->next != NULL)
  {
    node = node->next;
  }

  node->next = malloc(sizeof(queue_list_t));
  node->next->c = c;
  queue->size++;
}

char queue_poll(queue_t *queue)
{
  if (queue->head == NULL)
  {
    return 0;
  }

  char c = queue->head->c;
  queue_list_t *temp = queue->head->next;
  free(queue->head);
  queue->head = temp;

  return c;
}

bool queue_is_empty(queue_t *queue)
{
  return queue->head == NULL;
}

void queue_print(queue_t *queue)
{
  queue_list_t *node = queue->head;
  while (node != NULL)
  {
    printf("%c ", node->c);
    node = node->next;
  }
  printf("\n");
}

int main(int argc, char **argv)
{
  queue_t *queue = queue_make();
  queue_push(queue, 'a');
  queue_push(queue, 'b');
  queue_print(queue);
  printf("%c\n", queue_poll(queue));
  queue_print(queue);
  queue_push(queue, 'c');
  queue_print(queue);
  printf("%c\n", queue_poll(queue));
  queue_print(queue);
  printf("%c\n", queue_poll(queue));
  queue_free(queue);
}
