#include <stdio.h>
#include <stdbool.h>

#include "bf.h"
#include "mem_array.h"
#include "test.h"

int main()
{
  // const char* src = "+++.>,++.";
  // const char *src = "++[>+<-]";
  // const char* src = ",[>+.<-.]";
  // const char* src = ",[>+<-]>.";
  // const char* src = "++++++++[->++++>+>>++>++>>+++>+<<<<<<<<]>[->++>+++>+++>+>+>++<<<<<<]>.>+++++.>----..+++.>----.>.>-.<<<.+++.------.<-.>>>+.>>++.";
  // char result[20];
  // interp(src, result);
  const char* src = "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.>++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.";
  bool test_result = test(src, "AB");
  printf("Test result: %d\n", test_result);
  print_memory();
}
