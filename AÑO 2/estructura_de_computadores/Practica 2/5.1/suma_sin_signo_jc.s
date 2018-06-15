.section .data
	.macro linea
		.int 1,1,1,1
	#	.int 2,2,2,2
	#	.int 1,2,3,4
	#	.int -1,-1,-1,-1
	#	.int 0xffffffff,0xffffffff,0xffffffff,0xffffffff
	#	.int 0x08000000,0x08000000,0x08000000,0x08000000
	#	.int 0x10000000,0x20000000,0x40000000,0x80000000
	.endm
lista: .irpc i,12345678
		linea
	.endr
longlista:
	.int	(.-lista)/4
resultado1:
	.int 0x01234567
resultado2:
	.int 0x01234567
formato:
	.ascii "suma = %llu \n\0"

.section .text
main: .global main

	mov $lista, %ebx
	mov longlista, %ecx
	call suma
	mov %eax, resultado1
	mov %esi, resultado2

	push resultado2
	push resultado1
	push $formato
	call printf

	mov $1, %eax
	mov $0, %ebx
	int $0x80

suma:
	push %edx
	mov $0, %esi #msb
	mov $0, %eax #lsb
	mov $0, %edx #indice

bucle:
	add (%ebx,%edx,4), %eax
	jc acarreo
	inc %edx
	cmp %edx,%ecx
	jne bucle
	pop %edx
	ret

acarreo:
	inc %esi
	inc %edx
	cmp %edx,%ecx
	jne bucle
	pop %edx
	ret
