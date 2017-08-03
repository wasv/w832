#include "w832.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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
    for(int i = 0; i < W832_MEMSIZE/2; i++)
    {
        printf("%02d: ", i);
        disp_row(w832->M[i]);
        printf(" %02d: ", i+W832_MEMSIZE/2);
        disp_row(w832->M[i+W832_MEMSIZE/2]);
        putc('\n', stdout);
    }

    putc('\n', stdout);
    printf(" A: ");
    disp_row(w832->A);

    printf(" PC: %02u", w832->PC);
    putc('\n', stdout);
}

char w832_asmline(char *line, size_t n) {
  uint8_t opcode = 0xFF;
  uint8_t index = 0;
  if(strncmp(line, "LOD", 3) == 0) {
    opcode = 0;
  } else if(strncmp(line, "STO", 3) == 0) {
    opcode = 1;
  } else if(strncmp(line, "CMP", 3) == 0) {
    opcode = 2;
  } else if(strncmp(line, "JMP", 3) == 0) {
    opcode = 3;
  } else if(strncmp(line, "ADD", 3) == 0) {
    opcode = 4;
  } else if(strncmp(line, "NEG", 3) == 0) {
    opcode = 5;
  } else if(strncmp(line, "AND", 3) == 0) {
    opcode = 6;
  } else if(strncmp(line, "NOT", 3) == 0) {
    opcode = 7;
  }

  char *end = &line[n];
  if(opcode == 0xFF) {
    return strtol(line, &end, 0);
  }
  index = strtol(&line[3], &end, 0);
  return (opcode << 5) | (index & 0x1F);
}

size_t w832_asmfile(FILE *fp, uint8_t *prog, size_t n) {
    char *line = NULL;
    size_t len = 0;
    size_t prog_len = 0;
    uint8_t iptr = 0;
    ssize_t read;

    for(prog_len = 0;prog_len < n; prog_len++)
    {
      read = getline(&line, &len, fp);
      if(read == -1) break;
      if(prog_len == n) break;
      if(strncmp(line, "ORG", 3) == 0) {
         char *end = &line[n];
         iptr = strtol(&line[3], &end, 0);
         iptr &= 0x1F;
      } else {
          prog[iptr++] = w832_asmline(line, read);
      }
    }
    free(line);
    return n;
}
