	.data
String:	.asciz	"Hello World"
	.text
	.global _start
_start:
	mov $String, %esi # make esi point to String
	mov $0,%ecx	  # zero count
loop:	cmpb $0,(%esi)	  # are we there yet?
	je exit
	inc %ecx
	inc %esi
	jmp loop
	

exit:		
# Make system call to exit program
	movl $1,%eax	# System call, function number 1 (prog. exit)
	movl $0,%ebx	# program exit code = 0
	int $0x80

	.end
