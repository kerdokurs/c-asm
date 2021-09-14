// võtame kasutusele standard input/output teegi
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// makrod, mis asendatakse kompileerimise ajal koodi sisse
#define MEM_LENGTH 16
#define MEM_WIDTH 8
#define MEM_HEIGHT (MEM_LENGTH / MEM_WIDTH)

typedef enum
{
	OK,
	OVERFLOW_ERROR,
	UNDERFLOW_ERROR
} error_t;

typedef struct
{
	char memory[MEM_LENGTH];
	int pointer;

	int sulge;
} muutujad_t;

muutujad_t muutujad;

// väljastab brainfucki mälu sisu
void print_memory()
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

/*
 * interpreteerib brainfucki koodi
 * src - lähtekoodi massiiv, mille viimane element on null-byte
 */
void interp(const char *src)
{
  int i = 0;
  char c;
  int code_length = strlen(src);

  while (c = src[i])
  { // põhimõttelt while c ei ole 0
    switch (c)
    {
    case '+':
      muutujad.memory[muutujad.pointer]++; // põhimõttelt memory[pointer] += 1 v memory[pointer] = memory[pointer] + 1;
      break;
    case '-':
      muutujad.memory[muutujad.pointer]--;
      break;
    case '>':
      if (muutujad.pointer >= MEM_LENGTH - 1)
      {
	printf("Pointer out of memory range: %d\n", OVERFLOW_ERROR);
	exit(OVERFLOW_ERROR);
      }

      muutujad.pointer++; // analoogne ülal oleva lausega
      break;
    case '<':
      if (muutujad.pointer <= 0)
      {
	printf("Pointer out of memory range: %d\n", UNDERFLOW_ERROR);
	exit(UNDERFLOW_ERROR);
      }

      muutujad.pointer--;
      break;
    case '.':                        // output
      printf("%c", muutujad.memory[muutujad.pointer]); // väljastab karakteri asukohalt memory[pointer]
      break;
    case ',':                        // input
      scanf("%c", &muutujad.memory[muutujad.pointer]); // võtab kasutajalt sisendi ja paneb memory[pointer] asukohta
      break;
    case '[':
      // TODO: fix algo
      if (muutujad.memory[muutujad.pointer] == 0)
      {
        muutujad.sulge = 1;
	while (muutujad.sulge) {
	  i++;
	  if (i >= code_length - 1) {
	    printf("Code pointer out of code range: %d\n", OVERFLOW_ERROR);
	    exit(OVERFLOW_ERROR);
	  }

          if (src[i] == '[')
            muutujad.sulge++;
          else if (src[i] == ']')
            muutujad.sulge--;
	}
      }
      break;
    case ']':
      if (muutujad.memory[muutujad.pointer] != 0)
      {
        muutujad.sulge = -1;
	while (muutujad.sulge) {
	  i--;

	  if (i <= 0) {
	    printf("Code pointer out of code range: %d\n", UNDERFLOW_ERROR);
	    exit(UNDERFLOW_ERROR);
	  }

          if (src[i] == '[')
            muutujad.sulge++;
          else if (src[i] == ']')
            muutujad.sulge--;
	}
      }
      break;
    }

    i++;
  }
}

int main()
{
  // const char* src = "+++.>,++.";
  const char *src = "++[>+<-]";
  // const char* src = ",[>+.<-.]";
  // const char* src = "++++++++[->++++>+>>++>++>>+++>+<<<<<<<<]>[->++>+++>+++>+>+>++<<<<<<]>.>+++++.>----..+++.>----.>.>-.<<<.+++.------.<-.>>>+.>>++.";
  interp(src);
  printf("\n");
  print_memory();
}
