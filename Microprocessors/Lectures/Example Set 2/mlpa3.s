	.data
shift_register: .long 0xaa9669aa
	.global get_random
	
	.text
get_random: 	
	push %ecx
	movl shift_register,%ecx
	shl %ecx
	mov %ecx,%eax
	js shift2_msb_is_not_set
	andl $0x10000000,%ecx
	je shift2_skip_or
	jmp shift2_or
shift2_msb_is_not_set:
	andl $0x10000000,%ecx
	jne shift2_skip_or
shift2_or:	
	or $1,%eax	
shift2_skip_or:
	mov %eax,shift_register
	pop %ecx
	ret	


	.end
