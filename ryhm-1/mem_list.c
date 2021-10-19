#include <stdio.h>
#include <stdlib.h>

#include "mem.h"
#include "error.h"
#include "list.h"

#define MEM_LENGTH 16
#define MEM_WIDTH 8
#define MEM_HEIGHT (MEM_LENGTH / MEM_WIDTH)

typedef struct memory_t
{
  list_t *memory;
  int pointer;
} memory_t;

memory_t *memory_make()
{
  memory_t *memory = malloc(sizeof(memory_t));
  memory->memory = list_make(50);
  memory->pointer = 0;

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
  list_set(mem->memory, mem->pointer, list_at(mem->memory, mem->pointer) - 1);
}

void inc(memory_t *mem)
{
  list_set(mem->memory, mem->pointer, list_at(mem->memory, mem->pointer) + 1);
}

/*
// Prindib brainfucki mälu sisu
void print_memory(void)
{
  int i = 0;
  for (; i < MEM_HEIGHT; i++)
  {
    int j = 0;
    for (; j < MEM_WIDTH; j++)
    {
      int idx = i * MEM_HEIGHT + j;
      printf("%d ", muutujad.memory[idx]);
    }

    printf("\n");
  }
}

void print(char *result)
{
  // TODO: kasuta muutujat, mis hoiab meeles juba väljastatud karakterite arvu, et järgmine väljastatav karakter panna sõnele otsa (puhvris/massiivis järgmise koha peale)
  sprintf((result + muutujad.char_amt), "%c", muutujad.memory[muutujad.pointer]);
  muutujad.char_amt++;
}

void input(void)
{
  scanf("%c", &muutujad.memory[muutujad.pointer]);
}

void left_loop(int *i, const char *src, int code_length)
{
  if (muutujad.memory[muutujad.pointer] == 0)
  {
    muutujad.sulge = 1;

    while (muutujad.sulge)
    {
      if (*i >= code_length)
      {
        printf("Overflow with code pointer");
        exit(OVERFLOW);
      }

      (*i)++;
      if (src[*i] == '[')
        muutujad.sulge++;
      if (src[*i] == ']')
        muutujad.sulge--;
    }
  }
}

void right_loop(int *i, const char *src, int code_length)
{
  if (muutujad.memory[muutujad.pointer] != 0)
  {
    muutujad.sulge = -1;

    while (muutujad.sulge)
    {
      if (*i <= 0)
      {
        printf("Underflow with code pointer");
        exit(UNDERFLOW);
      }

      (*i)--;
      if (src[*i] == '[')
        muutujad.sulge++;
      if (src[*i] == ']')
        muutujad.sulge--;
    }
  }
}
*/
