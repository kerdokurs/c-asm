#pragma once

typedef struct memory_t memory_t;

memory_t *memory_make();

void memory_free(memory_t *mem);

void move_left(memory_t *mem);
void move_right(memory_t *mem);

void dec(memory_t *mem);
void inc(memory_t *mem);

void print_memory(memory_t *mem);

void print(memory_t *mem, FILE *output);
void input(memory_t *mem);

void left_loop(memory_t *mem, int *i, const char* src, int code_length);
void right_loop(memory_t *mem, int *i, const char* src, int code_length);
