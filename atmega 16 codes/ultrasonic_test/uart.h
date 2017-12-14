#ifndef _UART_H___
#define _UART_H___

void init_usart(unsigned int baud); 
void usart_putchar(char data);

void send2uart(char *buffer);
void send_ATcommand(char *buffer);
void print_uart(char *buffer);

char process_uart_data(char uart_buffer);


#endif /* _UART_H___ */
