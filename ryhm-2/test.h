#pragma once

#define ASSERT(msg, cond) printf("%s  %s\n", msg, cond ? "OK" : "FAIL")

bool test(const char* in, const char* out);
