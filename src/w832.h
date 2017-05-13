#ifndef W832_H
#define W832_H
#include <stdint.h>

#define W832_MEMSIZE 32

struct w832_state {
    uint8_t M[W832_MEMSIZE];
    uint8_t A, PC;
};

/* Initializes state of w832. */
void w832_init(struct w832_state *w832);

/* Completes one cycle of w832 operation. */
void w832_step(struct w832_state *w832);

/* displays current state of w832 instance. */
void w832_disp(struct w832_state *w832);

#endif
