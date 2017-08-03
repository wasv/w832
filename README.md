# w832
A sample instruction set, assembler, and emulator. Uses 3 bit opcodes and 5 bit memory addresses. Can address 32 bytes of memory.

## Dependencies
A POSIX C compiler, probably requires GCC. Untested on Windows.

## Building
```
make run
```

## Assembling Programs
```
editor prog.asm
bin/w832_asm prog.asm prog.bin
bin/w832_sim prog.bin
```

## Assembly Language Reference
All instructions can act on the memory, program counter, and the primary register A (the only general purpose register).

* `LOD n` LOAD value from memory address N into register A.
* `STO n` STORE register A in memory address N.
* `CMP n` COMPARE register A to memory address N. Skip next instruction if equal.
* `JMP n` JUMP PC to memory address N.
* `ADD n` ADD value from memory address N to register A.
* `NEG`   TWOS COMPLEMENT NEGATE value in register A.
* `AND n` AND value from memory address N with register A.
* `NOT`   BINARY NEGATE value in register A.

* `0x[0-F]+` will insert a literal hexadecimal value into memory.
* `[0-9]+` will insert a literal decimal value into memory.
* `0[0-9]+` will insert a literal octal value into memory.

* `ORG n` Only affects assembly process. Places the following
  instruction at memory location n, the one after that at n+1, and so on.
  
## 

## Credits
Inspired by [c88](https://github.com/aquila12/c88-js), which is based on the [SSEM](https://en.wikipedia.org/wiki/Manchester_Small-Scale_Experimental_Machine). I also have a modified fork of [c88](https://github.com/aquila12/c88-js) called [c1616](https://github.com/wastevensv/c1616-js).
