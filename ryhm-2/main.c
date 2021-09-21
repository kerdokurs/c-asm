#include <stdio.h>

#include "bf.h"

int main()
{
  // const char* src = "+++.>,++.";
  const char *src = "++[>+<-]";
  // const char* src = ",[>+.<-.]";
  // const char* src = "++++++++[->++++>+>>++>++>>+++>+<<<<<<<<]>[->++>+++>+++>+>+>++<<<<<<]>.>+++++.>----..+++.>----.>.>-.<<<.+++.------.<-.>>>+.>>++.";
  interp(src);
  printf("\n");
  print_memory();
}
