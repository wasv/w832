# w8-32 Opcodes

 Name            | b7-5   | RTN
-----------------|--------|-----------
`LOD` - Load     |  `000` | `A <- M[i]`
`STO` - Store    |  `001` | `M[i] <- A`
`CMP` - Compare  |  `010` | `(A - M[i]) == 0? P++`
`JMP` - Jump     |  `011` | `P <- i`
`ADD` - Add      |  `100` | `A <- A + M[i]`
`NEG` - Negate   |  `101` | `A <- -A`
`AND` - And      |  `110` | `A <- A & M[i]`
`NOT` - Not      |  `111` | `A <- ~A`

## Notation
* A - Accumulator Register
* M - Memory array (32 bytes)
* i - Lower 5 bits of instruction (bits 4-0), index into memory
* P - Program counter
