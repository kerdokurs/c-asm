#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "test.h"
#include "bf.h"
#include "mem_array.h"

int main()
{
  // hello world programm
  // const char* str = "++++++++[>++++[>++>++>+++>+++>+<<<<-]>+>+>->>[<][<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
  // const char *str = ",[>+<-]>.";
  const char *str = "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.";
  bool result = test(str, "A");
  printf("%d\n", result);
  // char result[80];
  // interp(str, result);
  // printf("%s\n", result);
  // print_memory();

  // output peaks olema 0 2 0 ...
  return 0;
}
