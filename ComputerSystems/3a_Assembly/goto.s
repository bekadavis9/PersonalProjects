	.file	"goto.c"
	.section	.rodata
	.align 8
.LC0:
	.string	"\nThe number is not 3. It is %d.\n"
.LC1:
	.string	"\nThe number is 3\n"
	.text
	.globl	chooseThree
	.type	chooseThree, @function
chooseThree:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	cmpl	$3, -4(%rbp)
	je	.L2
	nop
.L3:
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	jmp	.L1
.L2:
	nop
.L4:
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
.L1:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	chooseThree, .-chooseThree
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$7, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	chooseThree
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-36)"
	.section	.note.GNU-stack,"",@progbits
