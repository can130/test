#include "uart.h"
#include "cpu_io.h"
#include "gpio.h"



void uart0_init(void)
{
	
	struct s5pc210_uart_bank *uart_base = (struct s5pc210_uart_bank *)S5PV210_UARTBASE;
 	struct s5pv210_gpio *gpio_base = (struct s5pv210_gpio *)S5PV210_GPIOBASE;
	unsigned int var;
      //��������
	var = readl(&gpio_base->gpio_a0.con);
	var &= ~0xff;
	var  |= 0x22;
	writel(var, &gpio_base->gpio_a0.con);

	//uart ��������
	_REG(&uart_base->ulcon) = 0x3;  /*8λ1λֹͣλ*/
	_REG(&uart_base->ucon) = 0x5;/*ʹ�ܷ��ͽ���*/
	_REG(&uart_base->ubrdiv) = 35;
	_REG(&uart_base->udivslot) = 0x80;
}

void uart0_sendchar(char c)
{
	struct s5pc210_uart_bank *uart_base = (struct s5pc210_uart_bank *)S5PV210_UARTBASE;
	//�ȴ��ϴη������
	while(!(_REG(&uart_base->utrstat)&(0x1<<2)));
	//����
	_REG(&uart_base->utxh) =c;
}

void uart0_sendstr(const char *str)
{
	while(*str)
	{
		uart0_sendchar(*str);
		str++;
	}
}
char uart0_getchar(void)
{
	struct s5pc210_uart_bank *uart_base = (struct s5pc210_uart_bank *)S5PV210_UARTBASE;
	//�ȴ��ϴη������
	while(!(_REG(&uart_base->utrstat)&(0x1<<0)));
	//����
	return _REG(&uart_base->utxh);
}