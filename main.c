#include "headers.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <n> <p>\n", argv[0]);
        return 1;
    }

    long n = strtol(argv[1], NULL, 10);
    long p = strtol(argv[2], NULL, 10);

    long pth_factor = pthFactor(n, p);

    printf("The %ldth factor of %ld is %ld\n", p, n, pth_factor);

    return 0;
}
