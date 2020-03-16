#ifndef _HOLBERTON_H
#define _HOLBERTON_H

#include <stdarg.h>

int _printf(const char *format, ...);

typedef struct function_caller
{
	char *c;
	void (*function)(va_list);
} function_caller;

#endif
