	.data
String:	.asciz	"Hello World"
	.text
	.global _start
_start:
	mov $String, %edi
	mov $-1,%ecx
	mov $0,%al
loop:	repne scasb
	not %ecx
	dec %ecx

exit:		
# Make system call to exit program
	movl $1,%eax	# System call, function number 1 (prog. exit)
	movl $0,%ebx	# program exit code = 0
	int $0x80

	.end
