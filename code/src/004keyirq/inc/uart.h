#ifndef _UART_LCQ_H
#define _UART_LCQ_H

void uart2_init(void);

void uart2_sendchar(char c);

void uart2_sendstr(const char *str);

void uart1_init(void);

void uart1_sendchar(char c);

void uart1_sendstr(const char *str);

#endif
