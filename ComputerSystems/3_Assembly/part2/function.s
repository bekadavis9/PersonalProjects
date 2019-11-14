# part2
# ask user for operation and 2 numbers
# add or subtract numbers
# print result


.global _start


########## Data ##########

# Useful constants
.equ STDIN          ,0
.equ STDOUT         ,1
.equ READ           ,0
.equ WRITE          ,1
.equ EXIT           ,60
.equ EXIT_SUCCESS   ,0 


.operation:
	.ascii "1:add\n2:subtract\nSelect an operation: "
.first:
	.ascii "\nEnter your first number: "
.second:
	.ascii "\nEnter your second number: "
.result:
	.ascii "\nResult: "

.newline:
	.ascii "\n"

.data
	op: .space 16 	#chosen operation
	a: .space 16 	#first number
	b: .space 16 	#second number
	ans: .space 16	#result of operation
	one: .byte 1


########## Code ##########
.text

# set up exit function
_exitProgram:
	movq $EXIT, %rax            
	movq $EXIT_SUCCESS, %rdi    
	syscall                     
	ret


# ask user to choose operation   
_askOperation: 
	movq $WRITE,%rax           
	movq $STDOUT,%rdi          
	leaq .operation, %rsi  
	movq $38, %rdx                   
	syscall                 
	ret  

# ask user for first number
_askFirst:
	movq $WRITE,%rax           
	movq $STDOUT,%rdi          
	leaq .first, %rsi  
	movq $26, %rdx                   
	syscall 
	ret 

# ask user for second number
_askSecond:
	movq $WRITE,%rax           
	movq $STDOUT,%rdi          
	leaq .second, %rsi  
	movq $27, %rdx                   
	syscall 
	ret

# print result of operation
_printAnswer:
	movq $WRITE,%rax           
	movq $STDOUT,%rdi          
	leaq .operation, %rsi  
	movq $11, %rdx                   
	syscall 
	ret


# get operation from user
_getOperation:
	movq $READ,%rax
	movq $STDIN,%rdi
	movq $0,op
	movq $op,%rsi
	movq $1, %rdx 
	syscall

# check value of operation - if 1 go to add, 2 go to subtract
_compOp:
	#leaq op,%r8
	#cmpq $1,(%r8)

	.if %r8 == 1
	jg .add
	.endif
	#jmp .add

	jmp .subtract

	syscall
		


# print operation
_printOperation:
	movq $WRITE,%rax
	movq $STDOUT,%rdi
	leaq op,%rsi
	movq $2,%rdx
	syscall
	ret


# get first number from user
_getFirst:
	movq $READ,%rax
	movq $STDIN,%rdi
	movq $0,a
	movq $a,%rsi
	movq $3, %rdx
	syscall

# get second number from user
_getSecond:
	movq $READ,%rax
	movq $STDIN,%rdi
	movq $0,b
	movq $b,%rsi
	movq $2, %rdx
	syscall


# print first number
_printFirst:
	movq $WRITE,%rax
	movq $STDOUT,%rdi
	leaq a,%rsi
	movq $3,%rdx
	syscall
	ret

# print second number
_printSecond:
	movq $WRITE,%rax
	movq $STDOUT,%rdi
	leaq b,%rsi
	movq $2,%rdx
	syscall
	ret

# print result of operation
_printResult:
	movq $WRITE,%rax
	movq $STDOUT,%rdi
	leaq ans,%rsi
	movq $2,%rdx
	syscall
	ret

 
# print new line
_newline:
	movq $WRITE,%rax           
	movq $STDOUT,%rdi          
	leaq .newline, %rsi  
	movq $1, %rdx                   
	syscall                     
	ret 


.add:
	movq $0,ans
	mov %bl,a
	add %bl,b
	mov ans,%bl
	syscall
	ret

.subtract:
	movq $0,ans
	mov %bl,a
	sub %bl,b
	mov ans,%bl
	ret


_start:
	movq %rsp,%rbp
	callq _askOperation
	callq _getOperation
	callq _newline
	#callq _printOperation

	callq _newline
	callq _askFirst
	callq _getFirst
	callq _newline
	#callq _printFirst

	callq _newline
	callq _askSecond
	callq _getSecond
	callq _newline
	#callq _printSecond
	
	callq _newline
	
	callq _compOp
	callq _printAnswer
	callq _printResult
	
	
	

	callq _exitProgram
	popq %rbp

