.globl _start
.globl main
.globl irq_c_hander
.global asm_irq



_start:

	bl  main
loop:
	b loop

irq_hander:
	stmfd	sp!,{r0-r3,lr}
	bl 	irq_c_hander
	ldmfd	sp!,{r0-r3,lr}
	subs	pc,lr,#4

asm_irq:
	b irq_hander
.end