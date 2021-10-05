#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "test.h"
#include "bf.h"
#include "mem_array.h"

/*
 * `argc` - käsurea argumentide arv
 * `argv` - käsurea argumendid (nende massiiv, viit sellele)
 */
int main(int argc, char **argv)
{
  const char *default_code = ",+.";
  interp_t params;

  // = {0} algväärtustab kõik massiivi elemendid 0-ga
  char expected[OUT_LEN] = { 0 };

  // järgnev for-tsükkel ja memset on ekvivalentsed
  // arusaadavama ja kiirem on võib-olla memset (uuri huvi korral funktsiooni lähemalt)
  for (int i = 0; i < OUT_LEN; i++)
    expected[i] = 0;
  memset(expected, 0, OUT_LEN);

  if (argc > 2)
  {
    char *cmd = argv[1];
    char *output = argv[2];
    strcpy(params.cmd, cmd);
    strcpy(expected, output);
  } else {
    printf("No code provided. Using default code.\n");
    strcpy(params.cmd, default_code);
  }

  // ÜLESANNE
  // TODO 1:
  // ./bf_array +++. A >+. B
  // 1. interpreteerib +++.
  // 2. võrdleb tulemust "A"
  // 3. interpreteerib >+.
  // 4. võrdleb tulemust "B"
  // TODO 2:
  // tühjendab mälu, algseadistab muutujad_t väljad, kasutades reset_memory()
  // TODO 3:
  // kontrolli, et ükski käsk ei ületaks käsumassiivi pikkust

  // hello world programm
  // const char* str = "++++++++[>++++[>++>++>+++>+++>+<<<<-]>+>+>->>[<][<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
  // const char *str = ",[>+<-]>.";
  // const char *str = "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.+.+.+.+.";
  interp(&params);
  printf("%s\n", params.output);

  ASSERT("KOOD 1", !strcmp(params.output, expected)); // vaata `strcmp` funktsiooni
  // 1. jooksuta programm argumentideta ja sisesta A
  // 2. kui saad väljundiks "KOOD 1 OK", siis on võrdlemine implementeeritud õigesti

  return 0;
}
