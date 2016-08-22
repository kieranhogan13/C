# sum all numbers from 0 to 10 and store result in 
	.data

Array:  .long	0,1,2,3,4,5,6,7,8,9,10 # int Array[] = {0,1,2,3,4,5,6,7,8,9,10};
Total: 	.long   0		       # int Total = 0;
	.text

	.global _start

# during execution eax will contain the running total for the array
## DATA FLOW FROM LEFT TO RIGHT --->

_start: mov $11,%ecx	# int Count = 11;  move actual no. 11 into ecx
			# $ IMPLIES ACTUAL VALUE, % IMPLIES REGISTER
	mov $0,%eax	# int WorkingTotal = 0;	
	mov $0,%esi	# int Index = 0;
loop:	add Array(%esi),%eax	# WorkingTotal = WorkingTotal = Array[Index];
	add $4,%esi	# Each array element takes up 4 bytes so point to next one
	dec %ecx	# Count--;
	jnz loop	# if count not zero go back to label 'loop'
	mov %eax,Total  # write result to memory

exit:		
# Make system call to exit program
	movl $1,%eax	# System call, function number 1 (prog. exit)
	movl $0,%ebx	# program exit code = 0
	int $0x80

	.end
