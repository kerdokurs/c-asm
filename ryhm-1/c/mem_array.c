#include <stdio.h>
#include <stdlib.h>

#include "mem.h"
#include "error.h"

#define MEM_LENGTH 8 * 32
#define MEM_WIDTH 8
#define MEM_HEIGHT (MEM_LENGTH / MEM_WIDTH)

typedef struct memory_t
{
  char memory[MEM_LENGTH];
  int pointer;
  int sulge;
} memory_t;

memory_t *memory_make()
{
  memory_t *memory = malloc(sizeof(memory_t));

  return memory;
}

void memory_free(memory_t *mem)
{
  // TODO
}

void move_left(memory_t *mem)
{
  if (mem->pointer <= 0)
  {
    printf("Pointer underflow\n");
    exit(UNDERFLOW);
  }

  mem->pointer--;
}

void move_right(memory_t *mem)
{
  if (mem->pointer >= MEM_LENGTH)
  {
    printf("Pointer overflow\n");
    exit(OVERFLOW);
  }

  mem->pointer++;
}

void dec(memory_t *mem)
{
  mem->memory[mem->pointer]--;
}

void inc(memory_t *mem)
{
  mem->memory[mem->pointer]++;
}

void print_memory(memory_t *mem)
{
  for (int i = 0; i < MEM_HEIGHT; i++)
  {
    for (int j = 0; j < MEM_WIDTH; j++)
    {
      int idx = i * MEM_HEIGHT + j;
      printf("%d ", mem->memory[idx]);
    }

    printf("\n");
  }
}

void print(memory_t *mem, FILE *output)
{
  fprintf(output, "%c", mem->memory[mem->pointer]);
}

void input(memory_t *mem)
{
  // TODO: Take input from file
  char c = (char) getc(stdin);
  // scanf("%c", &muutujad.memory[muutujad.pointer]);
  mem->memory[mem->pointer] = c;
}

void left_loop(memory_t *mem, int *i, const char *src, int code_length)
{
  if (mem->memory[mem->pointer] == 0)
  {
    mem->sulge = 1;

    while (mem->sulge)
    {
      if (*i >= code_length)
      {
        printf("Overflow with code pointer");
        exit(OVERFLOW);
      }

      (*i)++;
      if (src[*i] == '[')
        mem->sulge++;
      if (src[*i] == ']')
        mem->sulge--;
    }
  }
}

void right_loop(memory_t *mem, int *i, const char *src, int code_length)
{
  if (mem->memory[mem->pointer] != 0)
  {
    mem->sulge = -1;

    while (mem->sulge)
    {
      if (*i <= 0)
      {
        printf("Underflow with code pointer");
        exit(UNDERFLOW);
      }

      (*i)--;
      if (src[*i] == '[')
        mem->sulge++;
      if (src[*i] == ']')
        mem->sulge--;
    }
  }
}
