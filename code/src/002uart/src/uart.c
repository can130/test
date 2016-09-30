#include "uart.h"
#include "cpu_io.h"
#include "gpio.h"



void uart0_init(void)
{
	
	struct s5pc210_uart_bank *uart_base = (struct s5pc210_uart_bank *)S5PV210_UARTBASE;
 	struct s5pv210_gpio *gpio_base = (struct s5pv210_gpio *)S5PV210_GPIOBASE;
	unsigned int var;
      //引脚配置
	var = readl(&gpio_base->gpio_a0.con);
	var &= ~0xff;
	var  |= 0x22;
	writel(var, &gpio_base->gpio_a0.con);

	//uart 参数配置
	_REG(&uart_base->ulcon) = 0x3;  /*8位1位停止位*/
	_REG(&uart_base->ucon) = 0x5;/*使能发送接收*/
	_REG(&uart_base->ubrdiv) = 35;
	_REG(&uart_base->udivslot) = 0x80;
}

void uart0_sendchar(char c)
{
	struct s5pc210_uart_bank *uart_base = (struct s5pc210_uart_bank *)S5PV210_UARTBASE;
	//等待上次发送完成
	while(!(_REG(&uart_base->utrstat)&(0x1<<2)));
	//发送
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
	//等待上次发送完成
	while(!(_REG(&uart_base->utrstat)&(0x1<<0)));
	//发送
	return _REG(&uart_base->utxh);
}