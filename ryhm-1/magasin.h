#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef enum
{
  MAG_OK = 0,
  MAG_OVERFLOW,
  MAG_UNDERFLOW
} magasin_error_t;

typedef struct magasin_t
{
  /*
   * Lisab magasini otsa elemendi val
   */
  magasin_error_t (*push)(struct magasin_t *mag, int8_t val);

  /*
   * Tagastab magasini peal oleva elemendi, aga seda ära ei eemalda
   */
  magasin_error_t (*peek)(struct magasin_t *mag, int8_t *out);

  /*
   * Võtab magasini pealt elemendi ja lisab viita out
   */
  magasin_error_t (*pop)(struct magasin_t *mag, int8_t *out);

  /*
   * Tagastab tõeväärtuse, kas magasin on tühi
   */
  bool (*is_empty)(struct magasin_t *mag);

  /*
   * Väljastab magasini sisu
   */
  void (*print)(struct magasin_t *mag);

  /*
   * Vabastab magasinile allokeeritud mälu
   */
  void (*free)(struct magasin_t *mag);

  // Selles muutujas hoiame magasini implementatsiooni (massiivil, linked listil vmt)
  void *impl;
} magasin_t;

// Konstruktor
magasin_t *magasin_make(void);
