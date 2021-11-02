#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "test.h"
#include "bf.h"
#include "mem.h"

#define DEFAULT_CMD_LEN 100

/*
 * `argc` - käsurea argumentide arv
 * `argv` - käsurea argumendid (nende massiiv, viit sellele)
 */
int main(int argc, char **argv)
{
  const char *default_code = ",.";
  interp_t params;
  params.mem = memory_make();

  FILE *output = NULL;
  bool output_is_file = false;

  if (argc > 1)
  {
    char *code_or_file = argv[1];

    // Test whether a file exists
    // Reference: https://www.gnu.org/software/libc/manual/html_node/Testing-File-Access.html
    // printf("%d\n", access("test.txt", F_OK));

    FILE *fp = fopen(code_or_file, "r");

    if (fp)
    {
      // Argument was file
      fseek(fp, 0, SEEK_END);
      long size = ftell(fp);
      rewind(fp);

      params.cmd = malloc(size * sizeof(char));
      fread(params.cmd, sizeof(char), size, fp);

      fclose(fp);
    }
    else
    {
      // Argument was code or file does not exist
      params.cmd = malloc(DEFAULT_CMD_LEN * sizeof(char));
      strcpy(params.cmd, code_or_file);
    }

    if (argc > 2)
    {
      // Third argument is output file
      output = fopen(argv[2], "a");

      if (output == NULL)
      {
        output = stdout;
      }
      else
      {
        output_is_file = true;
      }
    }
    else
    {
      // Write to stdout
      output = stdout;
    }
  }
  else
  {
    params.cmd = malloc(DEFAULT_CMD_LEN * sizeof(char));
    strcpy(params.cmd, default_code);
    output = stdout;
  }

  // TODO: Fix list implementation
  // TODO: Fix and finish mem_list implementation

  params.output = output;

  printf("%s\n", params.cmd);
  interp(&params);

  print_memory(params.mem);

  if (params.cmd)
  {
    free(params.cmd);
  }

  if (output_is_file && output)
  {
    fclose(output);
  }

  return 0;
}

