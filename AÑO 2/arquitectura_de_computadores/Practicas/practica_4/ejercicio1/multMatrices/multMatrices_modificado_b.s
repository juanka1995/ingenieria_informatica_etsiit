	.file	"multMatrices_modificado_b.c"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"Primer elemento resultado: %u\n"
	.align 8
.LC1:
	.string	"Ultimo elemento resultado: %u\n"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC3:
	.string	"Tiempo:\t%8.6f\n"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB4:
	.section	.text.startup,"ax",@progbits
.LHOTB4:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB38:
	.cfi_startproc
	subq	$56, %rsp
	.cfi_def_cfa_offset 64
	xorl	%esi, %esi
	xorl	%edi, %edi
	movq	%fs:40, %rax
	movq	%rax, 40(%rsp)
	xorl	%eax, %eax
.L2:
	leal	(%rdi,%rdi), %ecx
	movl	%edi, %edx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L3:
	movl	%edx, matrizA(%rsi,%rax)
	movl	%ecx, matrizB(%rsi,%rax)
	addq	$4, %rax
	addl	$2, %edx
	addl	$4, %ecx
	cmpq	$4000, %rax
	jne	.L3
	addl	$2, %edi
	addq	$4000, %rsi
	cmpl	$2000, %edi
	jne	.L2
	xorl	%edi, %edi
	movq	%rsp, %rsi
	call	clock_gettime
	movl	$matrizB, %edi
	movl	$traspuesta, %r8d
.L5:
	leaq	4000000(%rdi), %rsi
	movq	%r8, %rdx
	movq	%rdi, %rax
	.p2align 4,,10
	.p2align 3
.L6:
	movl	(%rax), %ecx
	addq	$4000, %rax
	addq	$4, %rdx
	movl	%ecx, -4(%rdx)
	cmpq	%rsi, %rax
	jne	.L6
	addq	$4, %rdi
	addq	$4000, %r8
	cmpq	$matrizB+4000, %rdi
	jne	.L5
	movl	$resultado+4000000, %r10d
	movl	$resultado, %r9d
.L10:
	movq	%r9, %rdi
	movq	%r9, %r8
	xorl	%esi, %esi
	subq	$resultado, %rdi
	.p2align 4,,10
	.p2align 3
.L12:
	movl	(%r8), %ecx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L8:
	movl	matrizA(%rdi,%rax), %edx
	imull	traspuesta(%rsi,%rax), %edx
	addq	$4, %rax
	addl	%edx, %ecx
	cmpq	$4000, %rax
	jne	.L8
	addq	$4000, %rsi
	movl	%ecx, (%r8)
	addq	$4, %r8
	cmpq	$4000000, %rsi
	jne	.L12
	addq	$4000, %r9
	cmpq	%r9, %r10
	jne	.L10
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movl	resultado(%rip), %edx
	movl	$.LC0, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	movl	resultado+3999996(%rip), %edx
	movl	$.LC1, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	movl	$1, %edi
	pxor	%xmm0, %xmm0
	movl	$.LC3, %esi
	cvtsi2sdq	%rax, %xmm0
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	divsd	.LC2(%rip), %xmm1
	cvtsi2sdq	%rax, %xmm0
	movl	$1, %eax
	addsd	%xmm1, %xmm0
	call	__printf_chk
	xorl	%eax, %eax
	movq	40(%rsp), %rdi
	xorq	%fs:40, %rdi
	jne	.L22
	addq	$56, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L22:
	.cfi_restore_state
	call	__stack_chk_fail
	.cfi_endproc
.LFE38:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE4:
	.section	.text.startup
.LHOTE4:
	.comm	resultado,4000000,32
	.comm	traspuesta,4000000,32
	.comm	matrizB,4000000,32
	.comm	matrizA,4000000,32
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC2:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
