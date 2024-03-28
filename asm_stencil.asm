section .text
bits 64
default rel

global asm_stencil

asm_stencil:
	; rcx - X

	movss xmm0, [rcx]
	addss xmm0, [rcx+4]
	addss xmm0, [rcx+8]
	addss xmm0, [rcx+12]
	addss xmm0, [rcx-4]
	addss xmm0, [rcx-8]
	addss xmm0, [rcx-12]

	ret