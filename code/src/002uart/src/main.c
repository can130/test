#include "led.h"
#include "cpu_io.h"
#include "uart.h"


static void mydelay(void)
{
	volatile unsigned int i=0xfffff;
	while(i--);
}




int main()
{
	 led_init(); 
	 uart0_init();


	while(1)
	{
	uart0_sendstr("hello word\r\n");
	 	led_blink(1);
		mydelay();
		led_blink(0);
		mydelay(); 
	}
	return 0;
}

