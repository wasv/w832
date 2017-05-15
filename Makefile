SIM_SRCS=src/w832_sim.c src/w832.c
CFLAGS=-ggdb

.PHONY: run all

all: bin/w832_sim test.bin

run: all
	bin/w832_sim test.bin

bin/w832_sim: ${SIM_SRCS}
	@mkdir -p bin
	gcc ${CFLAGS} -o $@ ${SIM_SRCS}

%.bin: %.hex
	xxd -r -p $< $@
