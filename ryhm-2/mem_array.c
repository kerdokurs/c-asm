#include <stdlib.h>
#include <stdio.h>

#include "mem_array.h"
#include "error.h"

// makrod, mis asendatakse kompileerimise ajal koodi sisse
#define MEM_LENGTH 16
#define MEM_WIDTH 8
#define MEM_HEIGHT (MEM_LENGTH / MEM_WIDTH)

typedef struct
{
	char memory[MEM_LENGTH];
	int pointer;

	int sulge;
	int char_amt;
} muutujad_t;

muutujad_t muutujad;

// väljastab brainfucki mälu sisu
void print_memory(void)
{
  // idee poolest 2 for-loopi teineteise sees
  // võiks tekitada sellise väljundi:
  // 3 2 0 0 0 0 0 0
  // 0 0 0 0 0 0 0 0

  for (int i = 0; i < MEM_HEIGHT; i++)
  {
    for (int j = 0; j < MEM_WIDTH; j++)
    {
      int idx = i * MEM_WIDTH + j;
      printf("%d ", muutujad.memory[idx]);
    }
    printf("\n");
  }
}

void move_left(void)
{
      if (muutujad.pointer <= 0)
      {
	printf("Pointer out of memory range: %d\n", UNDERFLOW_ERROR);
	exit(UNDERFLOW_ERROR);
      }

      muutujad.pointer--;
}

void move_right(void)
{
 	if (muutujad.pointer >= MEM_LENGTH - 1)
      {
	printf("Pointer out of memory range: %d\n", OVERFLOW_ERROR);
	exit(OVERFLOW_ERROR);
      }

      muutujad.pointer++;
}

void inc(void)
{
      muutujad.memory[muutujad.pointer]++; // põhimõttelt memory[pointer] += 1 v memory[pointer] = memory[pointer] + 1;
}

void dec(void)
{
      muutujad.memory[muutujad.pointer]--;
}

void print(char* result)
{
      sprintf(result + muutujad.char_amt, "%c", muutujad.memory[muutujad.pointer]); // väljastab karakteri asukohalt memory[pointer]
      muutujad.char_amt++; // muutujad.char_amt += 1 või muutujad.char_amt = muutujad.char_amt + 1;
}

void input(void)
{
      scanf("%c", &muutujad.memory[muutujad.pointer]); // võtab kasutajalt sisendi ja paneb memory[pointer] asukohta
}

int loop_left(int i, const char* src, int code_length)
{
      if (muutujad.memory[muutujad.pointer] == 0)
      {
        muutujad.sulge = 1;
	while (muutujad.sulge) {
	  if (i >= code_length - 1) {
	    printf("Code pointer out of code range: %d\n", OVERFLOW_ERROR);
	    exit(OVERFLOW_ERROR);
	  }

	  i++;
          if (src[i] == '[')
            muutujad.sulge++;
          else if (src[i] == ']')
            muutujad.sulge--;
	}
      }

      return i;
}

int loop_right(int i, const char* src, int code_length)
{
      if (muutujad.memory[muutujad.pointer] != 0)
      {
        muutujad.sulge = -1;
	while (muutujad.sulge) {
	  if (i <= 0) {
	    printf("Code pointer out of code range: %d\n", UNDERFLOW_ERROR);
	    exit(UNDERFLOW_ERROR);
	  }

	  i--;
          if (src[i] == '[')
            muutujad.sulge++;
          else if (src[i] == ']')
            muutujad.sulge--;
	}
      }

      return i;
}
