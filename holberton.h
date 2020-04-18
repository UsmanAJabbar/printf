#ifndef _HOLBERTON_H
#define _HOLBERTON_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct f_call - whateva
 * @c: format specifier scanner
 * @f: function caller
 */
typedef struct f_call
{
	char c;
	int (*f)(va_list);
} f_call;

int _printf(const char *format, ...);
int _putchar(char c);
int getprinter(char, va_list);
int printf_c(va_list);
int printf_str(va_list);
int printf_i_d(va_list);
int printf_r(va_list);
int printf_R(va_list);
int printf_b(va_list);
int print_bin(int n);

#endif
