#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipp_t {
  int sisu;
  struct tipp_t *vasak;
  struct tipp_t *parem;
} tipp_t;

static tipp_t *make_puu(int sisu)
{
  tipp_t *juur = malloc(sizeof(tipp_t));
  juur->sisu = sisu;
  return juur;
}

static tipp_t *parse_puu(const char *str, tipp_t *juur)
{
  const int size = 10;
  char temp[size];
  char *temp_loc = temp;
  char c;
  int x = 0;
  while (c = *str++)
  {
    if (c == '(')
    {
      // Add child
      // Parse next brackets
      continue;
    } else if (c == ')')
    {
      // go back
      continue;
    } else if (c == ' ')
    {
      int sisu = atoi(temp);
      temp_loc = temp;
      memset(temp, size, 0);
      if (x == 0)
      {
        juur->sisu = sisu;
      } else if (x == 1)
      {
        juur->vasak = make_puu(sisu);
      } else if (x == 2)
      {
        juur->parem = make_puu(sisu);
      }
      x++;
    }
    *(temp_loc++) = c;
  }
}

int main()
{
  const char *str = "(0 1 (2 3 4))";
  tipp_t *juur = make_puu(0);
  parse_puu(str, juur);

  return 0;
}
