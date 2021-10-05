#pragma once

#include <stdbool.h>

#define ASSERT(msg, cond) printf("%s  %s\n", msg, cond ? "OK" : "FAIL")

bool test(const char* in, const char* out);
