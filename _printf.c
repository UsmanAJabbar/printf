#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - acts a printf function
 * @format: contains specifiers
 * Return: Void
 */
int _printf(const char *format, ...)
{
	int index, jindex;
	va_list arguments;
	function_caller modulus[] = {
		{"%c", printf_c},
		{"%i", printf_i},
		{"%f", printf_f},
		{"%s", printf_str},
	};

	va_start(argument, format);

	while (format && format[index]) /* while there's something to test */
	{
		jindex = 0;

		while (jindex < 4) /* while all of modulus hasn't been checked, check! */
		{
			if (format[index] == modulus[jindex].s) /* if match found */
			{
				modulus[jindex].f(formatter); /* modulus masking printf func */
				break; /* if found, break */
			}
			jindex++; /* if no match, check the next array in modulus */
		}
		index++; /* check the next specifier in format */
	}
	printf("\n");
	va_end(formatter); /* clear all + memory */
}
