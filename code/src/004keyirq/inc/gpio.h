#ifndef _ASM_ARCH_GPIO_LCQ_H
#define _ASM_ARCH_GPIO_LCQ_H

#define S5PV210_GPIOBASE  (0XE0200000)
#define S5PV210_UARTBASE  (0xE2900000)
#define S5PV210_GPIOHBASE  (0xE0200C20)

struct s5pc210_gpio_bank {
	unsigned int con;
	unsigned int dat;
	unsigned int pud;
	unsigned int drv;
	unsigned int con_pdn;
	unsigned int pud_pdn;
	unsigned char res1[8];
};

struct s5pv210_gpio {
	struct s5pc210_gpio_bank  gpio_a0;
	struct s5pc210_gpio_bank  gpio_a1;
	struct s5pc210_gpio_bank  gpio_b;
	struct s5pc210_gpio_bank  gpio_c0;
	struct s5pc210_gpio_bank  gpio_c1;
	struct s5pc210_gpio_bank  gpio_d0;
	struct s5pc210_gpio_bank  gpio_d1;
	struct s5pc210_gpio_bank  gpio_e0;
	struct s5pc210_gpio_bank  gpio_e1;
	struct s5pc210_gpio_bank  gpio_f0;
	struct s5pc210_gpio_bank  gpio_f1;
	struct s5pc210_gpio_bank  gpio_f2;
	struct s5pc210_gpio_bank  gpio_f3;
	struct s5pc210_gpio_bank  gpio_g0;
	struct s5pc210_gpio_bank  gpio_g1;
	struct s5pc210_gpio_bank  gpio_g2;
	struct s5pc210_gpio_bank  gpio_g3;
	struct s5pc210_gpio_bank  gpio_i;
	struct s5pc210_gpio_bank  gpio_j0;
	struct s5pc210_gpio_bank  gpio_j1;
	struct s5pc210_gpio_bank  gpio_j2;
	struct s5pc210_gpio_bank  gpio_j3;
	struct s5pc210_gpio_bank  gpio_j4;
};

struct s5pc210_gpioh_bank {
	unsigned int con;
	unsigned int dat;
	unsigned int pud;
	unsigned int drv;
};

struct s5pc210_GPIOH{
	struct s5pc210_gpioh_bank  gpio_h0;
	struct s5pc210_gpioh_bank  gpio_h1;
	struct s5pc210_gpioh_bank  gpio_h2;
};

struct s5pc210_uart_bank
{
	unsigned int ulcon;
	unsigned int ucon;
	unsigned int ufcon;
	unsigned int umcon;
	unsigned int utrstat;
	unsigned int uerstat;
	unsigned int ufstat;
	unsigned int umstat;
	unsigned int utxh;
	unsigned int urxh;
	unsigned int ubrdiv;
	unsigned int udivslot;
	unsigned int uintp;
	unsigned int uintsp;
	unsigned int uimtm;
	unsigned char res1[4];
	unsigned char res2[0x3c0]
}; 

struct s5pc210_uart
{
	struct s5pc210_uart_bank UART1;
	struct s5pc210_uart_bank UART2;
	struct s5pc210_uart_bank UART3;
};


#endif