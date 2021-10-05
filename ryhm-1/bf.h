#pragma once

#define CMD_LEN 200 // sisendkäsu puhvri pikkus
#define BUF_LEN 16  // väljundi puhvri pikkus

// interpretaatori parameetrid
typedef struct
{
  char cmd[CMD_LEN]; // sisendkäsk, mis tuleb argumendina käsurealt
  char output[BUF_LEN]; // programmi väljund
} interp_t;

/*
 * Interpreteerib brainfucki koodi, mis on `params` structi `cmd` massiivis
 * `params` - viit interpretaatori parameetrite structile
 */
void interp(interp_t *params); 
