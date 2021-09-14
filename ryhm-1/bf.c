#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_LENGTH 8
#define MEM_WIDTH 8
#define MEM_HEIGHT (MEM_LENGTH / MEM_WIDTH)

typedef struct
{
	char memory[MEM_LENGTH];
	int pointer;
	int sulge;
} interp_muutujad_t;

enum Error
{
	OK = 0,
	OVERFLOW = 1,
	UNDERFLOW = 2
};

interp_muutujad_t muutujad;

// Prindib brainfucki mälu sisu
void print_memory()
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

/*
* Interpreteerib brainfucki.
* src - karakterite massiiv, mille lõpus on null-byte
*/
void interp(const char *src)
{
  int i = 0;
  char c;
  int code_length = strlen(src);
  while (c = src[i])
  {
    switch (c)
    {
    case '+':
      muutujad.memory[muutujad.pointer]++;
      break;
    case '-':
      muutujad.memory[muutujad.pointer]--;
      break;
    case '<':
      if (muutujad.pointer <= 0) {
	printf("Pointer underflow\n");
	exit(UNDERFLOW);
      }

      muutujad.pointer--;
      break;
    case '>':
      if (muutujad.pointer >= MEM_LENGTH) {
	printf("Pointer overflow");
	exit(OVERFLOW);
      }

      muutujad.pointer++;
      break;
    case '.':
      printf("%c", muutujad.memory[muutujad.pointer]);
      break;
    case ',':
      scanf("%c", &muutujad.memory[muutujad.pointer]);
      break;
    case '[':
      if (muutujad.memory[muutujad.pointer] == 0)
      {
        muutujad.sulge = 1;

	while (muutujad.sulge) {
		if (i >= code_length) {
			printf("Overflow with code pointer");
			exit(OVERFLOW);
		}

		i++;
                if (src[i] == '[') muutujad.sulge++;
                if (src[i] == ']') muutujad.sulge--;
	}
      }

      break;
    case ']':
      if (muutujad.memory[muutujad.pointer] != 0)
      {
        muutujad.sulge = -1;

	while (muutujad.sulge) {
		if (i <= 0) {
			printf("Underflow with code pointer");
			exit(UNDERFLOW);
		}

		i--;
                if (src[i] == '[') muutujad.sulge++;
                if (src[i] == ']') muutujad.sulge--;
	}
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
