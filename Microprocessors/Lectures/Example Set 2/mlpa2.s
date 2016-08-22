	.data
	.global F1, copymem
	.text
F1:	enter $0,$0

	leave
	ret

copymem:
	enter $0,$0
	push %esi
	push %edi
	push %ecx
	pushf
	cld
	movl 8(%ebp),%esi
	movl 12(%ebp),%edi
	movl 16(%ebp),%ecx
	rep movsb
	popf
	pop %ecx
	pop %edi
	pop %esi
	leave
	ret

	.end