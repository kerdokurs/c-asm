// võtame kasutusele standard input/output teegi
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bf.h"
#include "mem_array.h"

typedef enum
{
	OK,
	OVERFLOW_ERROR,
	UNDERFLOW_ERROR
} error_t;

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
      inc();
      break;
    case '-':
      dec();
      break;
    case '>':
      move_right();
      break;
    case '<':
      move_left();
      break;
    case '.':                        // output
      print();
      break;
    case ',':                        // input
      input();
      break;
    case '[':
      i = loop_left(i, src, code_length);
      break;
    case ']':
      i = loop_right(i, src, code_length);
      break;
    }

    i++;
  }
}
