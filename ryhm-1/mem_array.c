#include <stdio.h>
#include <stdlib.h>

#include "mem_array.h"
#include "error.h"

#define MEM_LENGTH 16
#define MEM_WIDTH 8
#define MEM_HEIGHT (MEM_LENGTH / MEM_WIDTH)

typedef struct
{
  // TODO: kasuta list_t
  // list_t *memory;       // brainfucki mälu
  char memory[MEM_LENGTH]; // brainfucki mälu
  int pointer;             // mäluviit
  int sulge;               // sulgude arv (kasutatud tsüklite jaoks)

  int char_amt;            // väljastatud karakterite arv
} muutujad_t;

muutujad_t muutujad;

void move_left(void)
{
  if (muutujad.pointer <= 0)
  {
    printf("Pointer underflow\n");
    exit(UNDERFLOW);
  }

  muutujad.pointer--;
}

void move_right(void)
{
  if (muutujad.pointer >= MEM_LENGTH)
  {
    printf("Pointer overflow\n");
    exit(OVERFLOW);
  }

  muutujad.pointer++;
}

void dec(void)
{
  muutujad.memory[muutujad.pointer]--;
}

void inc(void)
{
  muutujad.memory[muutujad.pointer]++;
}

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
