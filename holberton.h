#ifndef _HOLBERTON_H
#define _HOLBERTON_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct f_char -	struct that pairs a char format specifier with its
 *					corresponding printing function
 * @c: format specifier
 * @f: function called
 */
typedef struct f_char
{
	char c;
	int (*f)(va_list);
} f_char;

/**
 * struct base_s - struct that pairs an int format specifier with a base value
 * @c: format specifier
 * @base: base value associated with @c. determines function behavior
 */
typedef struct base_s
{
	char c;
	int base;
} base_s;

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
