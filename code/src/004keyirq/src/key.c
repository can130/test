#include "cpu_io.h"
#include "gpio.h"
#include "key.h"

extern void  asm_irq(void );
void key_init(void)
{
	struct s5pc210_GPIOH *gpioh_base = (struct s5pc210_GPIOH *)S5PV210_GPIOHBASE;
	unsigned int var;

	/*外部引脚进行功能选择 ENIT*/
	var = _REG(&gpioh_base->gpio_h2.con);
	var |= 0xf;  // enit[16]模式
	_REG(&gpioh_base->gpio_h2.con) = var;

	/*配置ENIT功能*/
	EXT_INT_2_CON  &= ~(0x07<<0);
	EXT_INT_2_CON  |= (0x02<<0);
	
	EXT_INT_2_MASK &=~(0x1<<0); //关闭中断屏蔽

	/*配置主中断控制器*/
	VIC0INTenable |=	0x1<<16; //打开中断

	VIC0VECTAADD16 = (unsigned int)key1_handler;  //中断函数
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

