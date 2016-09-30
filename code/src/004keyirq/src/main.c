#include "led.h"
#include "cpu_io.h"
#include "uart.h"
#include "key.h"

static void mydelay(void)
{
	volatile unsigned int i=0xfffff;
	while(i--);
}


int main()
{
	Irq_init();
	 led_init(); 
	 uart1_init();
	key_init();

	while(1)
	{
	uart1_sendstr("hello word\r\n");
	 	led_blink(1);
		mydelay();
		led_blink(0);
		mydelay(); 
	}
	return 0;
}

