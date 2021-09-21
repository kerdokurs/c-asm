#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bf.h"
#include "error.h"
#include "mem_array.h"

/*
* Interpreteerib brainfucki.
* src - karakterite massiiv, mille lõpus on null-byte
*/
void interp(const char *src, char *result)
{
  int i = 0;
  char c;
  int code_length = strlen(src);

  while (c = src[i])
  {
    switch (c)
    {
    case '+':
      inc();
      break;
    case '-':
      dec();
      break;
    case '<':
      move_left();
      break;
    case '>':
      move_right();
      break;
    case '.':
      print(result);
      break;
    case ',':
      input();
      break;
    case '[':
      i = left_loop(i, src, code_length);
      break;
    case ']':
      i = right_loop(i, src, code_length);
      break;
    case '$':
      // TODO: Implement yourself
      // For example: print memory location or memory content as int
      break;
    case '#':
      break;
    }

    i++;
  }
}
