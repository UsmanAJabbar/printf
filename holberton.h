#ifndef _HOLBERTON_H
#define _HOLBERTON_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);

typedef struct f_call
{
	char c;
	void (*f)(va_list);
} f_call;

int get_printer(char, va_list);
void printf_c(va_list);
void printf_str(va_list);
void printf_i_d(va_list);

#endif
