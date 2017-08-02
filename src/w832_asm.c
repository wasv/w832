#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "w832.h"

int main(int argc, char **argv) {
    if(argc == 1)
    {
	fputs("No program specified.\n", stderr);
	return -1;
    }
    /* Read program from file */
    FILE *f = fopen(argv[1], "r");
    if(f == NULL)
    {
	fputs("File not found.\n", stderr);
	return -1;
    }
    uint8_t prog[W832_MEMSIZE];
    memset(prog, 0, W832_MEMSIZE);
    w832_asmfile(f, prog, sizeof(prog));
    fclose(f);

    FILE *fo = fopen(argv[2], "wb");
    fwrite(prog,sizeof(prog[0]),W832_MEMSIZE,fo);
    fclose(fo);
    return 0;
}
