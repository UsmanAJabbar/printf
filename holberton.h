#ifndef _HOLBERTON_H
#define _HOLBERTON_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/**
 * struct f_str -	struct that pairs a char format specifier with its
 *					corresponding printing function
 * @c: format specifier
 * @f: function called
 */
typedef struct f_str
{
	char c;
	int (*f)(va_list);
} f_str;

/**
 * struct f_num - struct that pairs an int format specifier with a base value
 * @c: format specifier
 * @exp: exp value associated with @c. determines function behavior
 * @hex: assists in printing characters for hexadecimal base. 0 for other bases
 */
typedef struct f_num
{
	char c;
	int exp;
	int hex;
} f_num;

int _printf(const char *format, ...);
int _putchar(char c);
int getprinter(const char **, va_list);
int p_c(va_list);
int p_s(va_list);
int p_r(va_list);
int p_R(va_list);
int p_S(va_list);
int p_p(va_list);
int p_num(f_num, unsigned long int, int);
int p_int(char, unsigned int);
int p_long(char, unsigned long int);

#endif
