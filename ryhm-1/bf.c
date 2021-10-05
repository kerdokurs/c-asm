#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bf.h"
#include "error.h"
#include "mem_array.h"

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
    }

    i++;
  }
}
