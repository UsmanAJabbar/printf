#ifndef _HOLBERTON_H
#define _HOLBERTON_H

#include <stdarg.h>

void _printf(const char *format, ...);
int _putchar(char c);

typedef struct f_call
{
	char c;
	void (*f)(va_list);
} f_call;

void printf_c(va_list);
void printf_i(va_list);
void printf_f(va_list);
void printf_str(va_list);

#endif
