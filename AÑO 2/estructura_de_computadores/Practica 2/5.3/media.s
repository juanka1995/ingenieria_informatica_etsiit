.section .data
	.macro linea
		.int 1,-2,1,-2
	#	.int 1,2,-3,-4
	#	.int 0x7FFFFFFF,0x7FFFFFFF,0x7FFFFFFF,0x7FFFFFFF
	#	.int 0x80000000,0x80000000,0x80000000,0x80000000
	#	.int 0xF0000000,0xE0000000,0xE0000000,0xD0000000
	#	.int -1,-1,-1,-1
	#	.int 0,-1,-1,-1
	#	.int 0,-2,-1,-1
	#	.int 1,-2,-1,-1
	#	................
	#	.int 32,-2,-1,-1
	#	................
	#	.int 63,-2,-1,-1
	#	.int 64,-2,-1,-1
	#	................
	#	.int 95,-2,-1,-1
	#	.int -31,-2,-1,-1
	#	................
	#	.int 0,-2,-1,-1
	.endm
lista: .irpc i,12345678
		linea
	.endr
longlista:
	.int	(.-lista)/4
cociente:
	.int 0x01234567
resto:
	.int 0x01234567
formato:
	.ascii "media = %d ; resto = %d \n\0"

.section .text
main: .global main

	mov $lista, %ebx
	mov longlista, %ecx
	call suma
	call division
	mov %eax, cociente
	mov %edx, resto

	push resto
	push cociente
	push $formato
	call printf

	mov $1, %eax
	mov $0, %ebx
	int $0x80

suma:
	push %ebp
	mov $0, %ebp #indice
	mov $0, %esi #lsb
	mov $0, %edi #msb

bucle:
	mov $0, %eax #lista
	mov $0, %edx #extension de signo
	add (%ebx,%ebp,4), %eax
	cdq # Extension de signo de %EAX:%EDX
	add %eax,%esi
	adc %edx,%edi
	inc %ebp
	cmp %ebp,%ecx
	jne bucle
	pop %ebp
	ret	

division:
	mov %esi,%eax
	mov %edi,%edx
	mov %ecx,%ebx # %ebx debe contener el divisor
	idiv %ebx # El cociente se guarda en %eax y el resto en %edx 
	ret
