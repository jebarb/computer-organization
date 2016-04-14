.data 0x0
   buffer:  .space 20
   newline:   .asciiz"\n"

.text 0x3000
.globl main

main:

ori     $sp, $0, 0x2ffc
addi    $fp, $sp, -4
addi    $sp, $sp, -4

#scan int
li $v0, 5
syscall

#do stuff
move $a0, $v0
slti $t0, $a0, 1
jal fibonacci

move $a0, $v0

#print result
li $v0, 1
syscall
bne $t0, $0, exit_from_main
li $v0, 4
la $a0, newline($0)
syscall
la $a0 0($0)
j main

exit_from_main:
ori     $v0, $0, 10
syscall
end_of_main:

