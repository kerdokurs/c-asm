#pragma once

// interpretaatori parameetrid
typedef struct
{
  char *cmd;    // sisendkäsk, mis tuleb argumendina käsurealt
  FILE *output;
  void *mem;
} interp_t;

/*
 * Interpreteerib brainfucki koodi, mis on `params` structi `cmd` massiivis
 * `params` - viit interpretaatori parameetrite structile
 */
void interp(interp_t *params); 
