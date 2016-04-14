.data 0x0
   nums:  .space 1000
   newline:   .asciiz "\n"
   test: .asciiz "testing\n"

.text 0x3000
.globl main

main:

ori     $sp, $0, 0x2ffc
addi    $fp, $sp, -4
addi    $sp, $sp, -4

#scan number of ints
li $v0, 5
syscall
move $s0, $v0
li $t0, 4
mul $s0, $s0, $t0

add $t0, $0, $0

#scan ints
input:
li $v0, 5
syscall
sw $v0, nums($t0)
addi $t0, $t0, 4
blt $t0, $s0, input

add $a0, $0, $0 #min
addi $a1, $s0, -4 #max
jal quicksort

add $t0, $0, $0

#print result
print:
lw $a0, nums($t0)
li $v0, 1
syscall
addi $t0, $t0, 4
beq $t0, $s0, exit_from_main
li $v0, 4
la $a0, newline($0)
syscall
j print

exit_from_main:
ori     $v0, $0, 10
syscall
end_of_main:


.globl quicksort

quicksort:

addi $sp, $sp, -8
sw $ra, 4($sp)
sw $fp, 0($sp)
addiu $fp, $sp, 4

addi $sp, $sp, -12
sw $s0, 8($sp)
sw $s1, 4($sp)
sw $s2, 0($sp)

move $s0, $a0
move $s1, $a1

bge $s0, $s1, return_from_quicksort

jal partition
move $s2, $v0
move $a0, $s0
move $a1, $s2
jal quicksort
add $a0, $s2, 4
move $a1, $s1
jal quicksort

return_from_quicksort:
lw $s0, -8($fp)
lw $s1, -12($fp)
lw $s2, -16($fp)
lw $ra, 0($fp)
lw $fp, -4($fp)
addiu $sp, $sp, 20
jr  $ra

end_of_quicksort:


.globl partition

partition:

addi $sp, $sp, -8
sw $ra, 4($sp)
sw $fp, 0($sp)
addiu $fp, $sp, 4

addi $sp, $sp, -20
sw $s0, 16($sp)
sw $s1, 12($sp)
sw $s2, 8($sp)
sw $s3, 4($sp)
sw $s4, 0($sp)

move $s0, $a0
move $s1, $a0

move $s0, $a0
move $s1, $a1
lw $s2, nums($s0)
addi $s0, $a0, -4
addi $s1, $a1, 4

outer_loop:
inner_loop_1:
addi $s0, $s0, 4
lw $s3, nums($s0)
blt $s3, $s2, inner_loop_1

inner_loop_2:
addi $s1, $s1, -4
lw $s4, nums($s1)
bgt $s4, $s2, inner_loop_2

move $v0, $s1
bge $s0, $s1, return_from_partition

sw $s3, nums($s1)
sw $s4, nums($s0)
j outer_loop

return_from_partition:
lw $s0, -8($fp)
lw $s1, -12($fp)
lw $s2, -16($fp)
lw $s3, -20($fp)
lw $s4, -24($fp)
lw $ra, 0($fp)
lw $fp, -4($fp)
addiu $sp, $sp, 28
jr  $ra

end_of_partition:
