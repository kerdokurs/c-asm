#pragma once

#define CMD_LEN 200 // koodi puhvri pikkus
#define OUT_LEN 16  // väljundi puhvri pikkus

// interpretaatori parameetrid
typedef struct
{
  char cmd[CMD_LEN];    // sisendkäsk, mis tuleb argumendina käsurealt
  char output[OUT_LEN]; // programmi väljund
  void *mem;
} interp_t;

/*
 * Interpreteerib brainfucki koodi, mis on `params` structi `cmd` massiivis
 * `params` - viit interpretaatori parameetrite structile
 */
void interp(interp_t *params); 
