#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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
  for (int i = 0; i < argc; i++)
  {
    printf("%s\n", argv[i]);
  }

  // const char* src = "+++.>,++.";
  // const char *src = "++[>+<-]";
  // const char* src = ",[>+.<-.]";
  // const char* src = ",[>+<-]>.";
  // const char* src = "++++++++[->++++>+>>++>++>>+++>+<<<<<<<<]>[->++>+++>+++>+>+>++<<<<<<]>.>+++++.>----..+++.>----.>.>-.<<<.+++.------.<-.>>>+.>>++.";
  // char result[20];
  // interp(src, result);
  const char* src = "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.>++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.";
  init_memory();
  interp_t params;
  strcpy(params.cmd, src);
  interp(&params);
  printf("%s\n", params.output);
  
  char expected[OUT_LEN];
  strcpy(expected, "AB");

  ASSERT("KOOD 1", !strcmp(params.output, expected));
  /*
  bool test_result = test(src, "AB");
  printf("Test result: %d\n", test_result);
  print_memory();
  */
}
