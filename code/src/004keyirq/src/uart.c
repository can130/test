#include "uart.h"
#include "cpu_io.h"
#include "gpio.h"

void uart1_init(void)
{
	
	struct s5pc210_uart *uart_base = (struct s5pc210_uart *)S5PV210_UARTBASE;
 	struct s5pv210_gpio *gpio_base = (struct s5pv210_gpio *)S5PV210_GPIOBASE;
	unsigned int var;
      //��������
	var = readl(&gpio_base->gpio_a0.con);
	var &= ~0xff;
	var  |= 0x22;
	writel(var, &gpio_base->gpio_a0.con);

	//uart ��������
	_REG(&uart_base->UART1.ulcon) = 0x3;  /*8λ1λֹͣλ*/
	_REG(&uart_base->UART1.ucon) = 0x5;/*ʹ�ܷ��ͽ���*/
	_REG(&uart_base->UART1.ubrdiv) = 35;
	_REG(&uart_base->UART1.udivslot) = 0x80;
}

void uart1_sendchar(char c)
{
	struct s5pc210_uart *uart_base = (struct s5pc210_uart *)S5PV210_UARTBASE;
	//�ȴ��ϴη������
	while(!(_REG(&uart_base->UART1.utrstat)&(0x1<<2)));
	//����
	_REG(&uart_base->UART1.utxh) =c;
}

void uart1_sendstr(const char *str)
{
	while(*str)
	{
		uart1_sendchar(*str);
		str++;
	}
}
char uart1_getchar(void)
{
	struct s5pc210_uart *uart_base = (struct s5pc210_uart *)S5PV210_UARTBASE;
	//�ȴ��ϴη������
	while(!(_REG(&uart_base->UART1.utrstat)&(0x1<<0)));
	//����
	return _REG(&uart_base->UART1.utxh);
}


void uart2_init(void)
{
	
	struct s5pc210_uart *uart_base = (struct s5pc210_uart *)S5PV210_UARTBASE;
 	struct s5pv210_gpio *gpio_base = (struct s5pv210_gpio *)S5PV210_GPIOBASE;
	unsigned int var;
      //�������� 
	var = readl(&gpio_base->gpio_a0.con);
	var &= ~0xff<<16;
	var  |= 0x22<<16;
	writel(var, &gpio_base->gpio_a0.con);

	//uart ��������
	_REG(&uart_base->UART2.ulcon) = 0x3;  /*8λ1λֹͣλ*/
	_REG(&uart_base->UART2.ucon) = 0x5;/*ʹ�ܷ��ͽ���*/
	_REG(&uart_base->UART2.ubrdiv) = 35;  /* ����λ���ò����� */
	_REG(&uart_base->UART2.udivslot) = 0x80;
}

void uart2_sendchar(char c)
{
	struct s5pc210_uart *uart_base = (struct s5pc210_uart *)S5PV210_UARTBASE;
	//�ȴ��ϴη������
	while(!(_REG(&uart_base->UART2.utrstat)&(0x1<<2)));
	//����
	_REG(&uart_base->UART2.utxh) =c;
}

void uart2_sendstr(const char *str)
{
	while(*str)
	{
		uart2_sendchar(*str);
		str++;
	}
}
char uart2_getchar(void)
{
	struct s5pc210_uart *uart_base = (struct s5pc210_uart *)S5PV210_UARTBASE;
	//�ȴ��ϴη������
	while(!(_REG(&uart_base->UART1.utrstat)&(0x1<<0)));
	//����
	return _REG(&uart_base->UART1.utxh);
}