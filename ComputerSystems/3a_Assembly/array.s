	.file	"array.c"
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
	subq	$1600, %rsp
	movl	$27, -1600(%rbp)
	movl	$36, -1520(%rbp)
	movl	$59, -1200(%rbp)
	movl	$73, -880(%rbp)
	movl	$84, -640(%rbp)
	movl	$90, -360(%rbp)
	movl	$102, -100(%rbp)
	movl	$178, 0(%rbp)
	movl	$0, %eax
	leave
	.cfi_restore 6
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-36)"
	.section	.note.GNU-stack,"",@progbits
