# w832
A sample instruction set and emulator. Uses 3 bit opcodes and 5 bit memory addresses. Can address 32 bytes of memory.

## Dependencies
* xxd commandline tool (for converting ASCII .hex files into a .bin program).
  * Alternatively, any hex editor will do.

## Building
```
make
bin/w832_sim test.bin
```

## Compiling Programs
```
editor program.hex
make program.bin
bin/w832_sim program.bin
```
