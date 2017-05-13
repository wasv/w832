#include <stdio.h>

#include "w832.h"

int main(int argc, char **argv ) {
    struct w832_state w832;
    w832_init(&w832);

    /* Read program from file. */
    FILE *f = fopen(argv[1], "rb");
    fread(w832.M, sizeof(w832.M[0]), W832_MEMSIZE, f);

    w832_disp(&w832);
    return 0;
}
