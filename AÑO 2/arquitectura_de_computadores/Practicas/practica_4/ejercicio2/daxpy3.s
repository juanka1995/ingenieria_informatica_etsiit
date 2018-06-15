	.file	"daxpy.c"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC4:
	.string	"Primer elemento resultado: %u\n"
	.align 8
.LC5:
	.string	"Ultimo elemento resultado: %u\n"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC7:
	.string	"Tiempo:\t%8.6f\n"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB8:
	.section	.text.startup,"ax",@progbits
.LHOTB8:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB38:
	.cfi_startproc
	subq	$56, %rsp
	.cfi_def_cfa_offset 64
	movq	%fs:40, %rax
	movq	%rax, 40(%rsp)
	xorl	%eax, %eax
	movdqa	.LC0(%rip), %xmm0
	movdqa	.LC1(%rip), %xmm4
	movdqa	.LC2(%rip), %xmm3
	movdqa	.LC3(%rip), %xmm2
	.p2align 4,,10
	.p2align 3
.L2:
	movdqa	%xmm0, %xmm1
	addq	$16, %rax
	paddd	%xmm3, %xmm1
	pslld	$1, %xmm1
	movaps	%xmm1, vectorA-16(%rax)
	movdqa	%xmm0, %xmm1
	paddd	%xmm4, %xmm0
	paddd	%xmm2, %xmm1
	pslld	$2, %xmm1
	movaps	%xmm1, vectorB-16(%rax)
	cmpq	$400000000, %rax
	jne	.L2
	movq	%rsp, %rsi
	xorl	%edi, %edi
	call	clock_gettime
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L3:
	movdqa	vectorB(%rax), %xmm0
	addq	$16, %rax
	movdqa	%xmm0, %xmm1
	pslld	$2, %xmm1
	paddd	%xmm1, %xmm0
	paddd	vectorA-16(%rax), %xmm0
	movaps	%xmm0, vectorA-16(%rax)
	cmpq	$400000000, %rax
	jne	.L3
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movl	vectorA(%rip), %edx
	movl	$.LC4, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	movl	$vectorA+399999996, %eax
	movl	(%rax), %edx
	movl	$.LC5, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	movl	$.LC7, %esi
	pxor	%xmm0, %xmm0
	movl	$1, %edi
	cvtsi2sdq	%rax, %xmm0
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	divsd	.LC6(%rip), %xmm0
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	movl	$1, %eax
	addsd	%xmm1, %xmm0
	call	__printf_chk
	xorl	%eax, %eax
	movq	40(%rsp), %rcx
	xorq	%fs:40, %rcx
	jne	.L9
	addq	$56, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L9:
	.cfi_restore_state
	call	__stack_chk_fail
	.cfi_endproc
.LFE38:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE8:
	.section	.text.startup
.LHOTE8:
	.comm	vectorB,400000000,32
	.comm	vectorA,400000000,32
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.long	0
	.long	1
	.long	2
	.long	3
	.align 16
.LC1:
	.long	4
	.long	4
	.long	4
	.long	4
	.align 16
.LC2:
	.long	1
	.long	1
	.long	1
	.long	1
	.align 16
.LC3:
	.long	2
	.long	2
	.long	2
	.long	2
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC6:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
