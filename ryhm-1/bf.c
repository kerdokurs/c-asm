#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bf.h"
#include "error.h"
#include "mem.h"

void interp(interp_t *params)
{
  int i = 0;
  char c;
  int code_length = strlen(params->cmd);

  while (c = params->cmd[i])
  {
    switch (c)
    {
    case '+':
      inc(params->mem);
      break;
    case '-':
      dec(params->mem);
      break;
    case '<':
      move_left(params->mem);
      break;
    case '>':
      move_right(params->mem);
      break;
/*
    case '.':
      print(params->output);
      break;
    case ',':
      input();
      break;
    case '[':
      left_loop(&i, params->cmd, code_length);
      break;
    case ']':
      // See funktsioon ei tagasta midagi, vaid muudab muutujat `i` viida alusel
      right_loop(&i, params->cmd, code_length);
      break;
    case '$':
      // TODO: Implement yourself
      // For example: print memory location or memory content as int
      // For example
      // print_memory_location();
      break;
    case '#':
      // For example
      // print_memory_as_int();
      break;
*/
    }

    i++;
  }
}
