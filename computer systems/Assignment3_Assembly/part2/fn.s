	.file	"fn.c"
	.text
	.globl	add
	.align	16, 0x90
	.type	add,@function
add:                                    # @add
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp2:
	.cfi_def_cfa_offset 16
.Ltmp3:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp4:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rsi
	addq	-16(%rbp), %rsi
	movq	%rsi, -24(%rbp)
	movq	-24(%rbp), %rax
	popq	%rbp
	ret
.Ltmp5:
	.size	add, .Ltmp5-add
	.cfi_endproc

	.globl	subtract
	.align	16, 0x90
	.type	subtract,@function
subtract:                               # @subtract
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp8:
	.cfi_def_cfa_offset 16
.Ltmp9:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp10:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rsi
	subq	-16(%rbp), %rsi
	movq	%rsi, -24(%rbp)
	movq	-24(%rbp), %rax
	popq	%rbp
	ret
.Ltmp11:
	.size	subtract, .Ltmp11-subtract
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp14:
	.cfi_def_cfa_offset 16
.Ltmp15:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp16:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	leaq	.L.str, %rdi
	movl	$0, -4(%rbp)
	movq	-16(%rbp), %rsi
	movb	$0, %al
	callq	printf
	leaq	.L.str1, %rdi
	movq	-24(%rbp), %rsi
	movl	%eax, -44(%rbp)         # 4-byte Spill
	movb	$0, %al
	callq	printf
	leaq	.L.str2, %rdi
	movq	-32(%rbp), %rsi
	movl	%eax, -48(%rbp)         # 4-byte Spill
	movb	$0, %al
	callq	printf
	cmpq	$1, -16(%rbp)
	movl	%eax, -52(%rbp)         # 4-byte Spill
	jne	.LBB2_2
# BB#1:
	movq	-24(%rbp), %rdi
	movq	-32(%rbp), %rsi
	callq	add
	movq	%rax, -40(%rbp)
	jmp	.LBB2_6
.LBB2_2:
	cmpq	$2, -16(%rbp)
	jne	.LBB2_4
# BB#3:
	movq	-24(%rbp), %rdi
	movq	-32(%rbp), %rsi
	callq	subtract
	movq	%rax, -40(%rbp)
	jmp	.LBB2_5
.LBB2_4:
	leaq	.L.str3, %rdi
	movb	$0, %al
	callq	printf
	movl	%eax, -56(%rbp)         # 4-byte Spill
.LBB2_5:
	jmp	.LBB2_6
.LBB2_6:
	leaq	.L.str4, %rdi
	movq	-40(%rbp), %rsi
	movb	$0, %al
	callq	printf
	movl	$0, %ecx
	movl	%eax, -60(%rbp)         # 4-byte Spill
	movl	%ecx, %eax
	addq	$64, %rsp
	popq	%rbp
	ret
.Ltmp17:
	.size	main, .Ltmp17-main
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Select an operation: \n1:add \n2:subtract %s\n"
	.size	.L.str, 44

	.type	.L.str1,@object         # @.str1
.L.str1:
	.asciz	"Enter your first number: %s\n"
	.size	.L.str1, 29

	.type	.L.str2,@object         # @.str2
.L.str2:
	.asciz	"Enter your second number: %s\n"
	.size	.L.str2, 30

	.type	.L.str3,@object         # @.str3
.L.str3:
	.asciz	"\ninvalid operation"
	.size	.L.str3, 19

	.type	.L.str4,@object         # @.str4
.L.str4:
	.asciz	"result: %d"
	.size	.L.str4, 11


	.ident	"clang version 3.4.2 (tags/RELEASE_34/dot2-final)"
	.section	".note.GNU-stack","",@progbits
