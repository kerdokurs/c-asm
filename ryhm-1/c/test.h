#pragma once

#include <stdbool.h>

#define ASSERT(msg, cond) printf("%s  %s\n", cond ? "OK  " : "FAIL", msg)

bool test(const char* in, const char* out);
