	.file	"array2.c"
	.text
	.globl	addElement
	.type	addElement, @function
addElement:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movq	%rcx, -24(%rbp)
	movq	%r8, -32(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %edx
	movq	-32(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jle	.L2
	movq	-8(%rbp), %rax
	movl	$16, %esi
	movq	%rax, %rdi
	call	realloc
	movq	%rax, -8(%rbp)
	movq	-32(%rbp), %rax
	movl	$16, (%rax)
.L2:
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-8(%rbp), %rax
	addq	%rax, %rdx
	movl	-16(%rbp), %eax
	movl	%eax, (%rdx)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	leal	1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	addElement, .-addElement
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
	movl	$3200, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	movl	$0, -12(%rbp)
	movl	$400, -16(%rbp)
	leaq	-16(%rbp), %rcx
	leaq	-12(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rcx, %r8
	movq	%rdx, %rcx
	movl	$27, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	addElement
	leaq	-16(%rbp), %rcx
	leaq	-12(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rcx, %r8
	movq	%rdx, %rcx
	movl	$36, %edx
	movl	$20, %esi
	movq	%rax, %rdi
	call	addElement
	leaq	-16(%rbp), %rcx
	leaq	-12(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rcx, %r8
	movq	%rdx, %rcx
	movl	$59, %edx
	movl	$100, %esi
	movq	%rax, %rdi
	call	addElement
	leaq	-16(%rbp), %rcx
	leaq	-12(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rcx, %r8
	movq	%rdx, %rcx
	movl	$73, %edx
	movl	$180, %esi
	movq	%rax, %rdi
	call	addElement
	leaq	-16(%rbp), %rcx
	leaq	-12(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rcx, %r8
	movq	%rdx, %rcx
	movl	$84, %edx
	movl	$240, %esi
	movq	%rax, %rdi
	call	addElement
	leaq	-16(%rbp), %rcx
	leaq	-12(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rcx, %r8
	movq	%rdx, %rcx
	movl	$90, %edx
	movl	$310, %esi
	movq	%rax, %rdi
	call	addElement
	leaq	-16(%rbp), %rcx
	leaq	-12(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rcx, %r8
	movq	%rdx, %rcx
	movl	$102, %edx
	movl	$375, %esi
	movq	%rax, %rdi
	call	addElement
	leaq	-16(%rbp), %rcx
	leaq	-12(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rcx, %r8
	movq	%rdx, %rcx
	movl	$178, %edx
	movl	$400, %esi
	movq	%rax, %rdi
	call	addElement
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-36)"
	.section	.note.GNU-stack,"",@progbits
