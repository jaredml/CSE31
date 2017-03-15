
	.text

main:
	li $a0, 0
	jal putDec
	li $a0, '\n'
	li $v0, 11
	syscall
	
	li $a0, 1
	jal putDec
	li $a0, '\n'
	li $v0, 11
	syscall
	
	li $a0, 196
	jal putDec
	li $a0, '\n'
	li $v0, 11
	syscall
	
	li $a0, -1
	jal putDec
	li $a0, '\n'
	li $v0, 11
	syscall
	
	li $a0, -452
	jal putDec
	li $a0, '\n'
	li $v0, 11
	syscall
	
	li $a0, 2
	jal mystery
	move $a0, $v0
	jal putDec
	li $a0, '\n'
	li $v0, 11
	syscall

	li $a0, 3
	jal mystery
	move $a0, $v0
	jal putDec
	li $a0, '\n'
	li $v0, 11
	syscall

	li 	$v0, 10		# terminate program
	syscall

putDec: 
	## FILL IN ##
	addi $sp, $sp, -12
	sw $ra, 0($sp)
	sw $a0, 4($sp)
	add $t0, $zero, $a0
	add $t1, $zero, 
	bgez $t0, pos
	sub $t0, $zero, $t0
	jal pos
pos:
	div $t0, $t0, 10
	mflo $t1
	bgez $t0, putDec
	move $a0, $t1
	#save remainder to the stack in $a0
	syscall
	
	addi $sp, $sp, 12
	
		jr	$ra		# returnv

mystery: bne $0, $a0, recur 	# 
 	li $v0, 0 		#
 	jr $ra 			#
 recur: sub $sp, $sp, 8 	#
 	sw $ra, 4($sp) 		#
 	sub $a0, $a0, 1 	#
 	jal mystery 		#
 	sw $v0, 0($sp) 		#
 	jal mystery 		#
 	lw $t0, 0($sp) 		#
 	addu $v0, $v0, $t0 	#
 	addu $v0, $v0, 1 	#
 	add $a0, $a0, 1 	#
 	lw $ra, 4($sp) 		#
 	add $sp, $sp, 8 	#
 	jr $ra 			#
