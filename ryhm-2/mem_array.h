#pragma once

void print_memory(void);

/**
 * Liigutab koodiviita ühe võrra paremale
 */
void move_left(void);

/**
 * Liigutab koodiviita ühe võrra vasakule
 */
void move_right(void);

/**
 * Suurendab koodiviida all olevat mäluauku ühe võrra
 */
void inc(void);

/**
 * Vähendab koodiviida all olevat mäluauku ühe võrra
 */
void dec(void);


void print(void);
void input(void);


int loop_left(int i, const char* src, int code_length);

int loop_right(int i, const char* src, int code_length);
