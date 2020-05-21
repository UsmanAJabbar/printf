#ifndef _HOLBERTON_H
#define _HOLBERTON_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define ITS_A_DIGIT (**in >= '0' && **in <= '9')

/**
 * struct num_s - struct that stores number formatting configurations
 * @spec:		format specifier
 * @power:		exp value associated with @spec. determines function behavior
 * @hex_char:	assists in printing chars for hex bases. 0 for other bases
 **/
typedef struct num_s
{
	char spec;
	int power;
	int hex_char;
} num_t;

/**
 * struct config_s - struct that stores print format configuration settings
 * @spec:		format specifier code
 * @len:		if 1, print long int. if -1, print short int.
 * @minus:		if 1, print right-aligned
 * @plus:		if 1, print the '+' sign before an integer
 * @space:		if 1, print placeholder chars with spaces
 * @zero:		if 1, print placeholder chars with zeroes
 * @hash:		if 1, print non-base 10 digits with prefixes
 * @width:		minimum number of chars to print
 * @precision:	maximum number of chars to print
 **/
typedef struct config_s
{
	int spec;
	int len;
	int minus;
	int plus;
	int space;
	int zero;
	int hash;
	int width;
	int precision;
} format;

/**
 * struct printer_s - matches a format specifier with a printer
 * @codes:		allowable format specifiers for...
 * @f:	...this specific printer
 **/
typedef struct printer_s
{
	char *codes;
	char *(*f)(format, va_list);
} printer;

size_t _strlen(char *s);

int _printf(const char *format, ...);

format format_config(const char **);

num_t *num_config(char c);

char *p_s(format, va_list);
char *p_num(format, va_list);
char *p_base10(format, va_list);
char *append(char *, char **, char *);
char *append_rev(char *, char **);
char *append_rot13(char *, char **);

unsigned long int get_max(int spec, int len);

void getprinter(const char **, char **, va_list);

#endif /* HOLBERTON_H */
