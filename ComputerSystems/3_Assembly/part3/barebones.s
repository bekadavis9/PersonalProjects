# Build an executable using the following:
#
# clang barebones.s -o barebones  # clang is another compiler like gcc
#
.text
_barebones:

.data

.globl main

main:
					# (1) What are we setting up here?
					# Ans: the stack
	pushq %rbp			#
	movq  %rsp, %rbp		#

					# (2) What is going on here
					# Ans: Writing .hello.str to a register
	movq $1, %rax			#
	movq $1, %rdi			#
	leaq .hello.str,%rsi		#


					# (3) What is syscall? We did not talk about this
					# in class.
					# Ans: a syscall is what causes the program to actually execute an instruction
							# i.e. printf, scanf, etc
	syscall				# Which syscall is being run?
					# Ans: sys_write

					# (4) What would another option be instead of
					# using a syscall to achieve this?
					# Ans: create a function to write the string and return it at the end

	movq	$60, %rax		# (5) We are again setting up another syscall
	movq	$0, %rdi		# What command is it?
					# Ans: sys_exit
	syscall

	popq %rbp			# (Note we do not really need
					# this command here after the syscall)

.hello.str:
	.string "Hello World!\n"
	.size	.hello.str,13		# (6) Why is there a 13 here?
					# Ans: it is the buffer for the length of the string - i.e. the number of characters in .hello.str
