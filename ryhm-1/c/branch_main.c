#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#define MEM_SZ 1000000

void to_upper_branchless(char *str, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        str[i] -= 32 * (str[i] >= 'a' && str[i] <= 'z');
    }
}

void to_upper(char *str, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
}

int main()
{
    struct timeval stop, start;
    char *mem = malloc(MEM_SZ);
    for (size_t t = 0; t < 10; ++t) {
        printf("Iteration: %ld\n====================\n", t);
        for (size_t i = 0; i < MEM_SZ; ++i)
            mem[i] = rand();

        gettimeofday(&start, NULL);
        to_upper(mem, MEM_SZ);
        gettimeofday(&stop, NULL);
        printf("branch took %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);

        for (size_t i = 0; i < MEM_SZ; ++i)
            mem[i] = rand();

        gettimeofday(&start, NULL);
        to_upper_branchless(mem, MEM_SZ);
        gettimeofday(&stop, NULL);
        printf("branchless took %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);

        printf("\n====================\n");
    }

    free(mem);
}
