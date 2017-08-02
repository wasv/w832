SIM_SRCS=src/w832_sim.c src/w832.c
ASM_SRCS=src/w832_asm.c src/w832.c
CFLAGS=-ggdb
INSTALL_DIR?=/usr/local/bin

.PHONY: run all install

all: bin/w832_sim bin/w832_asm

run: all test.bin
	bin/w832_sim test.bin

install: all
	cp bin/w832_sim bin/w832_asm ${INSTALL_DIR}

bin/w832_sim: ${SIM_SRCS}
	@mkdir -p bin
	gcc ${CFLAGS} -o $@ ${SIM_SRCS}

bin/w832_asm: ${ASM_SRCS}
	@mkdir -p bin
	gcc ${CFLAGS} -o $@ ${ASM_SRCS}

%.bin: %.hex
	xxd -r -p $< $@

%.bin: %.asm
	bin/w832_asm $< $@
