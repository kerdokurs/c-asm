#include <stdio.h>
#include <stdbool.h>

#include "bf.h"
#include "mem_array.h"
#include "test.h"

/*
 * `argc` - argumentide arv
 * `argv` - argumentide (sõnede) massiiv 
 */
int main(int argc, char **argv)
{
  // TODO: Print all program command line arguments
  // Input: ./bf_array 1 2 3
  // Ouput: 1 2 3

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
