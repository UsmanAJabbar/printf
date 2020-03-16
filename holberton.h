#ifndef _HOLBERTON_H
#define _HOLBERTON_H

#include <stdarg.h>

int _printf(const char *format, ...);

typedef struct f_call
{
	char *c;
	void (*f)(va_list);
} f_call;

#endif
