	.file	"daxpy.c"
	.comm	vectorA,400000000,32
	.comm	vectorB,400000000,32
	.section	.rodata
	.align 8
.LC0:
	.string	"Primer elemento resultado: %u\n"
	.align 8
.LC1:
	.string	"Ultimo elemento resultado: %u\n"
.LC3:
	.string	"Tiempo:\t%8.6f\n"
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
	subq	$112, %rsp
	movl	%edi, -84(%rbp)
	movq	%rsi, -96(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$5, -60(%rbp)
	movl	$0, -68(%rbp)
	jmp	.L2
.L3:
	movl	-68(%rbp), %eax
	addl	$1, %eax
	leal	(%rax,%rax), %edx
	movl	-68(%rbp), %eax
	cltq
	movl	%edx, vectorA(,%rax,4)
	movl	-68(%rbp), %eax
	addl	$2, %eax
	leal	0(,%rax,4), %edx
	movl	-68(%rbp), %eax
	cltq
	movl	%edx, vectorB(,%rax,4)
	addl	$1, -68(%rbp)
.L2:
	cmpl	$99999999, -68(%rbp)
	jle	.L3
	leaq	-48(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
	movl	$0, -64(%rbp)
	jmp	.L4
.L5:
	movl	-64(%rbp), %eax
	cltq
	movl	vectorB(,%rax,4), %eax
	imull	-60(%rbp), %eax
	movl	%eax, %edx
	movl	-64(%rbp), %eax
	cltq
	movl	vectorA(,%rax,4), %eax
	addl	%eax, %edx
	movl	-64(%rbp), %eax
	cltq
	movl	%edx, vectorA(,%rax,4)
	addl	$1, -64(%rbp)
.L4:
	cmpl	$99999999, -64(%rbp)
	jle	.L5
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
	movl	vectorA(%rip), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$vectorA+399999996, %eax
	movl	(%rax), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movq	-32(%rbp), %rdx
	movq	-48(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm1
	movq	-24(%rbp), %rdx
	movq	-40(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	movsd	.LC2(%rip), %xmm2
	divsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -56(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, -104(%rbp)
	movsd	-104(%rbp), %xmm0
	movl	$.LC3, %edi
	movl	$1, %eax
	call	printf
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L7
	call	__stack_chk_fail
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC2:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
