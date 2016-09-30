#ifndef _S5PV210_CPU_LCQ_H
#define _S5PV210_CPU_LCQ_H

//#define S5PV210_WATACHDOG_BASE 0XE27000000
//#define S5PV210_GPIOBASE               0XE02000000
//#define S5PV210_CLOCK_BASE		    0XE01000000


#define   _REG(adr)     (*(volatile unsigned int *)(adr))

#define   readb(adr)      (*(volatile unsigned char *)(adr))
#define   readw(adr)     (*(volatile unsigned short *)(adr))
#define   readl(adr)       (*(volatile unsigned int *)(adr))

#define writeb(value,adr)   ((*(volatile unsigned char *)(adr))=(value))  
#define writew(value,adr)   ((*(volatile unsigned short *)(adr))=(value))   
#define writel(value,adr)   ((*(volatile unsigned int*)(adr))=(value))  
#endif 

