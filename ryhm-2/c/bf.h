#pragma once

#define CMD_LEN 200
#define OUT_LEN 16

typedef struct
{
  char cmd[CMD_LEN];
  char output[OUT_LEN];
} interp_t;

void interp(interp_t *params);
