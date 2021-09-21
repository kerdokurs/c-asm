#pragma once

void move_left(void);
void move_right(void);

void dec(void);
void inc(void);

void print_memory(void);

void print(char* result);
void input(void);

int left_loop(int i, const char* src, int code_length);
int right_loop(int i, const char* src, int code_length);
