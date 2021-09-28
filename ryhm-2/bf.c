// võtame kasutusele standard input/output teegi
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bf.h"
#include "mem_array.h"

/*
 * interpreteerib brainfucki koodi
 * src - lähtekoodi massiiv, mille viimane element on null-byte
 */
void interp(const char *src, char *result)
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
      print(result);
      break;
    case ',':                        // input
      input();
      break;
    case '[':
      printf("[%d ", i);
      loop_left(&i, src, code_length);
      printf(", %d\n", i);
      break;
    case ']':
      printf("]%d ", i);
      loop_right(&i, src, code_length);
      printf(", %d\n", i);
      break;
    case '$':
      // TODO: Implement new oprator
      // For example:
      //   Print current memory location (pointer)
      //   Print debug: print memory value as int
      break;
    case '#':
      break;
    }

    i++;
  }
}
