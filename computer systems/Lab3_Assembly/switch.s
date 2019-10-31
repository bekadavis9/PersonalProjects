	.file	"switch.c"
	.section	.rodata
.LC0:
	.string	"\nThe number is 1.\n"
.LC1:
	.string	"\nThe number is 2.\n"
.LC2:
	.string	"\nThe number is 3.\n"
.LC3:
	.string	"\nThe number is 4.\n"
.LC4:
	.string	"\nThe number is 5.\n"
.LC5:
	.string	"\nThe number is 0.\n"
	.align 8
.LC6:
	.string	"\nThe number is between 1 and 5.\n"
.LC7:
	.string	"\nThe number is %d.\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, %edi
	movl	$0, %eax
	call	time
	movl	%eax, %edi
	call	srand
	call	rand
	movl	%eax, %ecx
	movl	$715827883, %edx
	movl	%ecx, %eax
	imull	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, -4(%rbp)
	cmpl	$6, -4(%rbp)
	ja	.L2
	movl	-4(%rbp), %eax
	movq	.L4(,%rax,8), %rax
	jmp	*%rax
	.section	.rodata
	.align 8
	.align 4
.L4:
	.quad	.L2
	.quad	.L3
	.quad	.L5
	.quad	.L6
	.quad	.L7
	.quad	.L8
	.quad	.L9
	.text
.L3:
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	jmp	.L10
.L5:
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	jmp	.L10
.L6:
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	jmp	.L10
.L7:
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	jmp	.L10
.L8:
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	jmp	.L10
.L9:
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	jmp	.L10
.L2:
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC7, %edi
	movl	$0, %eax
	call	printf
.L10:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-36)"
	.section	.note.GNU-stack,"",@progbits
