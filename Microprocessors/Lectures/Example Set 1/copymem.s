	.data
Source:  .long	0,1,2,3,4,5,6,7,8,9,10
Dest: 	.fill 11,4,0
	.text
	.global _start
_start:	mov $44,%ecx     # how many bytes to copy in ecx
	mov $Source,%esi # put address of Source block into esi
	mov $Dest,%edi   # put address of Dest block into edi
	cld
	rep movsl 	# repeatedly move data
	
exit:		
# Make system call to exit program
	movl $1,%eax	# System call, function number 1 (prog. exit)
	movl $0,%ebx	# program exit code = 0
	int $0x80

	.end
