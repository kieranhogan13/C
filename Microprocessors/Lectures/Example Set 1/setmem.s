	.EQU BUFSIZE,8
	.data
# create an 8 byte space
Buffer:	.skip	BUFSIZE
	.text
	.global _start

_start: mov $BUFSIZE,%ecx
	mov $Buffer,%edi
	mov $42,%al
loop:	mov %al,(%edi)			
	inc %edi
	dec %ecx
	jnz loop

exit:		
# Make system call to exit program
	movl $1,%eax	# System call, function number 1 (prog. exit)
	movl $0,%ebx	# program exit code = 0
	int $0x80

	.end
