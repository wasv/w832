SIM_SRCS=src/w832_sim.c src/w832.c
ASM_SRCS=src/w832_asm.c src/w832.c
CFLAGS=-ggdb
INSTALL_DIR?=/usr/local/bin

.PHONY: run all install

all: bin/w832_sim bin/w832_asm

run: all test.bin
	bin/w832_sim test.bin

install: ${INSTALL_DIR}/w832_sim ${INSTALL_DIR}/w832_asm

${INSTALL_DIR}/w832_sim: bin/w832_sim
	cp $< $@
${INSTALL_DIR}/w832_asm: bin/w832_asm
	cp $< $@

bin/w832_sim: ${SIM_SRCS}
bin/w832_asm: ${ASM_SRCS}

bin/*:
	@mkdir -p bin
	gcc ${CFLAGS} -o $@ $^

%.bin: %.hex
	xxd -r -p $< $@

%.bin: %.asm
	bin/w832_asm $< $@
