# mpla1.s
# assembly language source file for mixed language programming example

	.data
# Declare any (global/static) data here
	.text
# Constancts and code go here.	
	.global UpperCase
# The equivalent C prototype of this function is as follows:
# void UpperCase(char *Str);
UpperCase:		
	push %ebp
	mov %esp,%ebp
# At this point the stack contents are as follows:
#	Address of string requiring conversion
#	Function call return address
#	Saved copy of EBP 	<-- EBP points here
	push %esi		# back up registers that
	push %eax		# are altered by this function
	mov 8(%ebp),%esi	# make esi point to the string
UCLoop:
	movb (%esi),%al		# read the first character of the string
	cmp $0,%al		# is it zero?
	je UCExit		# If so, then exit
	andb $0xdf,%al		# Otherwise make uppercase by clearing bit5 (see ASCII table)
	movb %al,(%esi)		# Write back changed character
	inc %esi		# move the pointer on a byte
	jmp UCLoop		# and repeat
	
UCExit:	
	pop %eax		# restore changed registers
	pop %esi		# NOTE: order of popping compared to pushing
	pop %ebp
	ret			# return to caller.
	.end

