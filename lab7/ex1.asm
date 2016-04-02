.data 0x0
   buffer:  .space 20
   newline:   .asciiz"\n"

.text 0x3000
.globl main

main:

ori     $sp, $0, 0x2ffc     # Initialize stack pointer to the top word below .text
                            # The first value on stack will actually go at 0x2ff8
                            #   because $sp is decremented first.
addi    $fp, $sp, -4        # Set $fp to the start of main's stack frame

addi    $sp, $sp, -4

#scan string
li $v0, 8
la $a0, buffer
li $a1, 20
syscall

jal a_to_i

#print result
move $a0, $v0
li $v0, 1
syscall
beq $a0, $0, exit_from_main
li $v0, 4
la $a0, newline($0)
syscall
la $a0 0($0)
j main


exit_from_main:
ori     $v0, $0, 10     # System call code 10 for exit
syscall                 # Exit the program
end_of_main:


.globl a_to_i

a_to_i:

addi    $sp, $sp, -8        # Make room on stack for saving $ra and $fp
sw  $ra, 4($sp)             # Save $ra
sw  $fp, 0($sp)             # Save $fp

addiu   $fp, $sp, 4         # Set $fp to the start of proc1's stack frame

addi    $sp, $sp, -16       # e.g., $s0, $s1, $s2, $s3
sw  $s0, 12($sp)            # Save $s0
sw  $s1, 8($sp)             # Save $s1
sw  $s2, 4($sp)             # Save $s2


add $s0, $a0, $0
add $v0, $0, $0
ori $s1, $0, 10

loop:
lb $s2, 1($s0)
beq $s2, $0, return_from_a_to_i
lb $s2, 0($s0)
sub $s2, $s2, 48
mult $v0, $s1
mflo $v0
add $v0, $v0, $s2
addi $s0, $s0, 1
j loop

return_from_a_to_i:
lw  $s0,  -8($fp)           # Restore $s0
lw  $s1, -12($fp)           # Restore $s1
lw  $s2, -16($fp)           # Restore $s2
lw  $ra, 0($fp)             # Restore $ra
lw  $fp, -4($fp)            # Restore $fp
addiu   $sp, $sp, 56        # Restore $sp
jr  $ra                     # Return from procedure

end_of_a_to_i:
