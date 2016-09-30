#ifndef _KEY_LCQ_H_
#define _KEY_LCQ_H_

#define PEXECPTION_IRQ  (*(volatile unsigned int *)(0XD0037418))  //0XD0037400 +0X18

#define EXT_INT_2_CON     (*(volatile unsigned int *)(0xE0200E08))
#define EXT_INT_2_MASK   (*(volatile unsigned int *)(0xE0200F08))
#define EXT_INT_2_PEND   (*(volatile unsigned int *)(0xE0200F48))

#define VIC0INTenable       (*(volatile unsigned int *)(0xF2000010))
#define VIC0ADDRESS        (*(volatile unsigned int *)(0xF2000F00))
#define VIC0VECTAADD16  (*(volatile unsigned int *)(0xF2000140))

void key_init(void);

void key1_handler(void);

void irq_c_hander(void);

void Irq_init(void);

void key_init(void);
#endif
