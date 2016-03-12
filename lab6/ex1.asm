.data 0x0
    stringin:    .space 5
    stringout:   .asciiz "\P2\n"
    newline:     .asciiz "\n"
    
.text 0x3000

main:
    #load and print P2
    la $a0, stringin($0)
    la $a1, stringout($0)
    li $v0, 8
    syscall
    li  $v0, 4
    la $a0, stringout($0)
    syscall

    #scan and print width
    li $v0, 5
    syscall
    move $8, $v0
    li  $v0, 1
    move $a0, $8
    syscall
    li  $v0, 4
    la $a0, newline($0)
    syscall
    la $a0 0($0)
     
    #scan and print height
    li $v0, 5
    syscall
    move $9, $v0
    li  $v0, 1
    move $a0, $9
    syscall
    li  $v0, 4
    la $a0, newline($0)
    syscall
    la $a0 0($0)

    #calculate loop length
    mult $8, $9
    mflo $14

    #scan and print max
    li $v0, 5
    syscall
    move $8, $v0
    li  $v0, 1
    li $a0, 255
    syscall
    li  $v0, 4
    la $a0, newline($0)
    syscall
    la $a0 0($0)
    
    li $13, 0

loop:
    #scan red and check for EOL
    li $v0, 5
    syscall	
    move $9, $v0
    blt $9, $0, end

    #scan green and blue
    li $v0, 5
    syscall	
    move $10, $v0
    li $v0, 5
    syscall	
    move $11, $v0
    
    #multiply red
    li $12, 30
    mult $9, $12
    mflo $9
    
    #mult green
    li $12, 59
    mult $10, $12
    mflo $10
    
    #mult blue
    li $12, 11
    mult $11, $12
    mflo $11
    
    #add colors
    add $9, $9, $10
    add $9, $9, $11

    #colors * 255
    li $25, 255
    mult $25, $9
    mflo $9
    
    #max*100
    li $12, 100
    mult $12, $8
    mflo $12
    
    #final grey color
    div $9, $12
    mflo $9
    
    #print grey
    li  $v0, 1
    move $a0, $9
    syscall
    addi $13, $13, 1
    beq $13, $14, end
    li  $v0, 4
    la $a0, newline($0)
    syscall
    la $a0 0($0)

    j loop

end:
    li $v0, 10
    syscall
    

