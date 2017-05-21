# w8-32 Opcodes

 Name           | b7-5   | RTN
----------------|--------|-----------
`LD` - Load     |  `000` | `A <- M[i]`
`ST` - Store    |  `001` | `M[i] <- A`
`CP` - Compare  |  `010` | `(A - M[i]) == 0? P++`
`JP` - Jump     |  `011` | `P <- i`
`AD` - Add      |  `100` | `A <- A + M[i]`
`NG` - Negate   |  `101` | `A <- -A`
`AN` - And      |  `110` | `A <- A & M[i]`
`NT` - Not      |  `111` | `A <- ~A`

## Notation
* A - Accumulator Register
* M - Memory array (32 bytes)
* i - Lower 5 bits of instruction (bits 4-0), index into memory
* P - Program counter
