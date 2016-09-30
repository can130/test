#include "cpu_io.h"
#include "gpio.h"
#include "key.h"

extern void  asm_irq(void );
void key_init(void)
{
	struct s5pc210_GPIOH *gpioh_base = (struct s5pc210_GPIOH *)S5PV210_GPIOHBASE;
	unsigned int var;

	/*�ⲿ���Ž��й���ѡ�� ENIT*/
	var = _REG(&gpioh_base->gpio_h2.con);
	var |= 0xf;  // enit[16]ģʽ
	_REG(&gpioh_base->gpio_h2.con) = var;

	/*����ENIT����*/
	EXT_INT_2_CON  &= ~(0x07<<0);
	EXT_INT_2_CON  |= (0x02<<0);
	
	EXT_INT_2_MASK &=~(0x1<<0); //�ر��ж�����

	/*�������жϿ�����*/
	VIC0INTenable |=	0x1<<16; //���ж�

	VIC0VECTAADD16 = (unsigned int)key1_handler;  //�жϺ���
}

void key1_handler(void)
{
	uart1_sendstr("key1 down");

	EXT_INT_2_PEND |= 0x01;
}

void irq_c_hander(void)
{
	void  (*handler)(void)=0;

	uart1_sendstr("it is in irq_c_hander\n");

	
	handler = (void (*)(void))VIC0ADDRESS;
	if(handler)
		handler();
}

void Irq_init(void)
{
/*	unsigned int tmp;
	tmp = *((unsigned int *)asm_irq)
	PEXECPTION_IRQ = tmp;
*/
	PEXECPTION_IRQ = (unsigned int)asm_irq;
}

