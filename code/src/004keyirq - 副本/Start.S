.globl _start
.globl main
_start:

	bl  main
loop:
	b loop
.end