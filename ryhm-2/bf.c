// võtame kasutusele standard input/output teegi
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bf.h"
#include "mem_array.h"

/*
 * interpreteerib brainfucki koodi
 */
void interp(interp_t *params)
{
  int i = 0;
  char c;
  int code_length = strlen(params->cmd);

  while (c = params->cmd[i])
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
      print(params->output);
      break;
    case ',':                        // input
      input();
      break;
    case '[':
      loop_left(&i, params->cmd, code_length);
      break;
    case ']':
      loop_right(&i, params->cmd, code_length);
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
