// võtame kasutusele standard input/output teegi
#include <stdio.h>

// makrod, mis asendatakse kompileerimise ajal koodi sisse
#define MEM_LENGTH 16
#define MEM_WIDTH 8
#define MEM_HEIGHT (MEM_LENGTH / MEM_WIDTH)

char memory[MEM_LENGTH];
int pointer = 0;

int sulge = 0;

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
      printf("%d ", memory[idx]);
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

  while (c = src[i])
  { // põhimõttelt while c ei ole 0
    switch (c)
    {
    case '+':
      memory[pointer]++; // põhimõttelt memory[pointer] += 1 v memory[pointer] = memory[pointer] + 1;
      break;
    case '-':
      memory[pointer]--;
      break;
    case '>':
      pointer++; // analoogne ülal oleva lausega
      break;
    case '<':
      pointer--;
      break;
    case '.':                        // output
      printf("%c", memory[pointer]); // väljastab karakteri asukohalt memory[pointer]
      break;
    case ',':                        // input
      scanf("%c", &memory[pointer]); // võtab kasutajalt sisendi ja paneb memory[pointer] asukohta
      break;
    case '[':
      if (memory[pointer] == 0)
      {
        sulge = 1;
        do
        {
          if (src[i] == '[')
            sulge++;
          else if (src[i] == ']')
            sulge--;
          i++;
        } while (sulge != 0);
      }
      break;
    case ']':
      if (memory[pointer] != 0)
      { // alternatiiv: if (memory[pointer])
        sulge = -1;
        do
        {
          if (src[i] == '[')
            sulge++;
          else if (src[i] == ']')
            sulge--;
          i--;
        } while (sulge != 0);
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
  interp(src);
  printf("\n\n");
  print_memory();
}
