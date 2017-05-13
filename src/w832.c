#include "w832.h"

#include <stdio.h>
#include <string.h>

/* Initializes state of w832. */
void w832_init(struct w832_state *w832) {
    memset(w832->M, 0, W832_MEMSIZE);
    w832->A = 0;
    w832->PC = 0;
}

/* Completes one cycle of w832 operation. */
void w832_step(struct w832_state *w832) {
    w832->PC += 1;
}


/* Private function for printing a byte in binary. */
void disp_row(uint8_t byte) {
    for(int i = 0; i < 8; i++)
    {
        if(((byte>>i) & 1) == 0)
        {
            putc('0', stdout);
        }
        else
        {
            putc('1', stdout);
        }
    }
}
/* displays current state of w832 instance. */
void w832_disp(struct w832_state *w832) {
    for(int i = 0; i < W832_MEMSIZE; i++)
    {
        printf("%02d: ", i);
        disp_row(w832->M[i]);
        putc('\n', stdout);
    }

    putc('\n', stdout);
    printf(" A: ");
    disp_row(w832->A);

    putc('\n', stdout);
    printf("PC: %02d", w832->PC);
    putc('\n', stdout);
}
