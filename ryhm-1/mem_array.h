#pragma once

void move_left(void);
void move_right(void);

void dec(void);
void inc(void);

void print_memory(void);

void print(char* result);
void input(void);

// Need funktsioonid võiks majandada muutujaga `i` ise. See tähendab ei tagasta mitte midagi
void left_loop(int *i, const char* src, int code_length);
void right_loop(int *i, const char* src, int code_length);

// NB!
// `int* x` on ekvivalentne `int *x`
// kuid `int* x, y` ja `int *x, y` ei ole - uuri ise täpsemalt, kui tunned huvi
