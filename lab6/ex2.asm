.data 0x0
   stringin:  .space 5
   stringout: .asciiz "\P2\n"
   newline:   .asciiz"\n"

.text 0x3000

main:
    #print P2
    li $v0, 4
    la $a0, stringout($0)
    syscall
    la $a0 0($0)

    #scan x1, x2, y1, y2, width
    li $v0, 5
    syscall
    move $8, $v0  #x1
    li $v0, 5
    syscall
    move $9, $v0  #x2
    li $v0, 5
    syscall
    move $10, $v0 #y1
    li $v0, 5
    syscall
    move $11, $v0 #y2
    li $v0, 5
    syscall
    move $12, $v0 #w

    #skip max and height
    li $v0, 5
    syscall
    mult $v0, $12
    mflo $25
    li $v0, 5
    syscall


    #calculate and print height, width
    sub $13, $9, $8
    addi $13, $13, 1
    li $v0, 1
    move $a0, $13
    syscall
    li $v0, 4
    la $a0, newline($0)
    syscall
    la $a0 0($0)
    sub $13, $11, $10
    addi $13, $13, 1
    move $a0, $13
    li $v0, 1
    syscall
    li $v0, 4
    la $a0, newline($0)
    syscall
    la $a0 0($0)
    li $v0, 1
    addi $a0, $0, 255
    syscall
    la $a0, 0($0)
    li $v0, 4
    la $a0, newline($0)
    syscall
    la $a0 0($0)
    li $13, 0

loop:
    div $13, $12
    mfhi $14  #x
    mflo $24  #y

    addi $13, $13, 1
    beq $13, $25, end

    #scan pixel
    li $v0, 5
    syscall
    move $a0, $v0

    blt $14, $8, loop
    bgt $14, $9, loop
    blt $24, $10, loop
    bgt $24, $11, loop

    li $v0,1
    syscall
    addi $16, $13, 1
    beq $25, $16, end
    li $v0, 4
    la $a0, newline($0)
    syscall
    la $a0 0($0)

    j loop

end:
    li $v0, 10
    syscall

