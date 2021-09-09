#include <stdio.h>

#define MEM_LENGTH 8
#define MEM_WIDTH (MEM_LENGTH / 8)

char memory[MEM_LENGTH];
int pointer = 0;

int sulge = 0;

// Prindib brainfucki mälu sisu
void print_memory()
{
  int i = 0;
  for (; i < MEM_WIDTH; i++)
  {
    int j = 0;
    for (; j < 8; j++)
    {
      int idx = i * MEM_WIDTH + j;
      printf("%d ", memory[idx]);
    }
    printf("\n");
  }
}

/*
* Interpreteerib brainfucki.
* src - karakterite massiiv, mille lõpus on null-byte
*/
void interp(const char *src)
{
  int i = 0;
  char c;
  // põhimõttelt
  // for (; c; c = src[i++])
  while (c = src[i])
  { // või while ((c = src[i] != NULL)) .., aga vajab include'i stdlib.h
    printf("%c", c);
    switch (c)
    {
    case '+':
      memory[pointer]++;
      break;
    case '-':
      memory[pointer]--;
      break;
    case '<':
      pointer--;
      break;
    case '>':
      // TODO: Lisa overflow protection
      pointer++;
      break;
    case '.':
      printf("%c", memory[pointer]);
      break;
    case ',':
      scanf("%c", &memory[pointer]);
      break;
    case '[':
      if (memory[pointer] == 0)
      {
        sulge = 0;
        do
        {
          if (src[i] == '[')
            sulge++;
          else if (src[i] == ']')
            sulge--;
          i++;
        } while (sulge);
      }
      break;
    case ']':
      if (memory[pointer] == 0)
      {
        sulge = -1;
        do
        {
          if (src[i] == '[')
            sulge++;
          else if (src[i] == ']')
            sulge--;
          i--;
        } while (sulge);
      }

      break;
    }

    i++;
  }
}

int main()
{
  // hello world programm
  // const char* str = "++++++++[>++++[>++>++>+++>+++>+<<<<-]>+>+>->>[<][<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++. ";
  const char *str = "++[>+<-]";
  interp(str);
  print_memory();
  // output peaks olema 0 2 0 ...
  return 0;
}
