	.data
Hello: .asciz	"Hello World\n"
	.text
	.global _start
_start:
	movl $4,%eax		# System call, function 4,write to file
	movl $1,%ebx		# file number 1 - the console (screen)
	movl $Hello,%ecx 	# address of string goes in ecx
	movl $12,%edx		# length of string in edx
	int $0x80		# call system


# Make system call to exit program
	movl $1,%eax	# System call, function number 1 (prog. exit)
	movl $0,%ebx	# program exit code = 0
	int $0x80

	.end
