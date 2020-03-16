#ifndef _HOLBERTON_H
#define _HOLBERTON_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);

typedef struct f_call
{
	char c;
	int (*f)(va_list);
} f_call;

int get_printer(char, va_list);
int printf_c(va_list);
int printf_str(va_list);
int printf_i_d(va_list);

#endif
