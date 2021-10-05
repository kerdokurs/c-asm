#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "test.h"
#include "bf.h"
#include "mem_array.h"

/*
 * `argc` - käsurea argumentide arv
 * `argv` - käsurea argumendid (nende massiiv, viit sellele)
 */
int main(int argc, char **argv)
{
  // TODO 2: kui käsurealt argumente ei tulnud, interpreteeri seda käsku
  const char *default_code = ",.";

  if (argc > 1) // argumentide arv > 1
  {
    for (int i = 1; i < argc; i++) // käime argumendid läbi
      printf("%s ", argv[i]);
    printf("\n");
  }

  // TODO: kasuta esimest käsureaargumenti brainfucki koodina ja interpreteeri see
  // TODO 3: kasuta teist käsureaargumenti testimiseks
  // näited:
  // `./bf_array ,.` jooksutab koodi `,.`
  // `./bf_array` jooksutab koodi muutujas `default_code`

  // hello world programm
  // const char* str = "++++++++[>++++[>++>++>+++>+++>+<<<<-]>+>+>->>[<][<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
  // const char *str = ",[>+<-]>.";
  const char *str = "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.+.+.+.+.";
  interp_t params;
  strcpy(params.cmd, str);
  interp(&params);
  printf("%s\n", params.output);

  // output peaks olema 0 2 0 ...
  return 0;
}
