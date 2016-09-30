#include "led.h"
#include "cpu_io.h"



static void mydelay(void)
{
	volatile unsigned int i=0xfffff;
	while(i--);
}




int main()
{
	 led_init(); 
	while(1)
	{
	 	led_blink(1);
		mydelay();
		led_blink(0);
		mydelay(); 
	}
	return 0;
}

