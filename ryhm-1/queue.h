#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef struct queue_list_t
{
  char c;
  struct queue_list_t *next;
} queue_list_t;

typedef struct
{
  struct queue_list_t *head;
  size_t size;
} queue_t;

queue_t *queue_make(void);

void queue_free(queue_t *queue);

void queue_push(queue_t *queue, const char c);

char queue_poll(queue_t *queue);

bool queue_is_empty(queue_t *queue);

void queue_print(queue_t *queue);
