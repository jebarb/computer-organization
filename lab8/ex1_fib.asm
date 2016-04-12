.globl fibonacci

fibonacci:

addi $sp, $sp, -8
sw $ra, 4($sp)
sw $fp, 0($sp)
addiu   $fp, $sp, 4

addi $sp, $sp, -4
sw $a0, 0($sp)
move $v0, $a0
blt $a0, 2, return_from_fibonacci
addi $a0, $a0, -1
jal fibonacci
lw $a0, 0($sp)
sw $v0, 0($sp)
addi $a0, $a0, -2
jal fibonacci
lw $v1, 0($sp)
add $v0, $v0, $v1

return_from_fibonacci:
lw $ra, 0($fp)
lw $fp, -4($fp)
addiu $sp, $sp, 12
jr $ra

