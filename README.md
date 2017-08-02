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
editor program.asm
bin/w832_asm program.asm program.bin
bin/w832_sim program.bin
```

## Credits
Inspired by [c88](https://github.com/aquila12/c88-js), which is based on the [SSEM](https://en.wikipedia.org/wiki/Manchester_Small-Scale_Experimental_Machine). I also have a modified fork of [c88](https://github.com/aquila12/c88-js) called [c1616](https://github.com/wastevensv/c1616-js).
