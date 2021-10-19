#pragma once

typedef struct memory_t memory_t;

memory_t *memory_make();

void memory_free(memory_t *mem);

void move_left(memory_t *mem);
void move_right(memory_t *mem);

void dec(memory_t *mem);
void inc(memory_t *mem);

void print_memory(void);

void print(char* result);
void input(void);

void left_loop(int *i, const char* src, int code_length);
void right_loop(int *i, const char* src, int code_length);
