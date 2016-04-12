.data 0x0
   buffer:  .space 20
   newline:   .asciiz"\n"

.text 0x3000
.globl main

main:

lw $t1, ($t0)
#ori $a0, $0, -1
#ori $a0, $0, 0xFFFF
