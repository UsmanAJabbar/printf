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
typedef struct f_str
{
	char c;
	int (*f)(va_list);
} f_str;

typedef struct base_s
{
	char c;
	int base;
} base_t;

int _printf(const char *format, ...);
int _putchar(char c);
int getprinter(char, va_list);
int p_c(va_list);
int p_s(va_list);
int p_r(va_list);
int p_R(va_list);
int p_num(char, int);
int p_int(char, int);
int p_b(int);

#endif
