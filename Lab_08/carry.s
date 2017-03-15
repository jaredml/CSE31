#num1: 	.word 0x7fffffff
	#la $t3, 0xffffffff 
	#la $t4, 1
	addu $t5, $t3, $t4
	sltu $t2, $t5, $t3 # there is carry if sum < any operand 