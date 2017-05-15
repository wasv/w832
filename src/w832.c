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
    uint8_t opcode = (w832->M[w832->PC] & 0xE0) >> 5;
    uint8_t index  =  w832->M[w832->PC] & 0x1F;
    switch(opcode)
    {
        case 0: /* Load */
            w832->A = w832->M[index];
            break;
        case 1: /* Store */
            w832->M[index] = w832->A;
            break;
        case 2: /* Compare */
            if(w832->A - w832->M[index] == 0)
            {
                if(++w832->PC == 32) w832->PC = 0;
            }
            break;
        case 3: /* Jump */
            w832->PC = index - 1;
            break;
        case 4: /* Add */
            w832->A = w832->A + w832->M[index];
            break;
        case 5: /* Negate */
            w832->A = -w832->A;
            break;
        case 6: /* And */
            w832->A = w832->A & w832->M[index];
            break;
        case 7: /* Not */
            w832->A = ~w832->A;
            break;
        default:
            puts("Invalid Opcode. This is probably a bug.");
    }
    if(++w832->PC == 32) w832->PC = 0;
}


/* Private function for printing a byte in binary. */
void disp_row(uint8_t byte) {
    for(int i = 7; i >= 0; i--)
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
    puts("\e[1;1H\e[2J");
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
    printf("PC: %02u", w832->PC);
    putc('\n', stdout);
}
