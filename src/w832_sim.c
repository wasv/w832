#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "w832.h"

int main(int argc, char **argv ) {
    /* Initialize emulator */
    struct w832_state w832;
    w832_init(&w832);

    if(argc == 1)
    {
        fputs("No program specified.\n", stderr);
        return -1;
    }
    /* Read program from file */
    FILE *f = fopen(argv[1], "rb");
    fread(w832.M, sizeof(w832.M[0]), W832_MEMSIZE, f);

    /* Clear screen */
    puts("\e[1;1H\e[2J");

    while(1)
    {
        /* Simulate one iteration */
        w832_step(&w832);
        /* Update display */
        w832_disp(&w832);

        usleep(250000);
    }
    puts("\e[1;1H\e[2J");
    return 0;
}
