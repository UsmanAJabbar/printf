#include <stdarg.h>
#include "holberton.h"

/**
 * print_all - acts a printf function
 * @format: contains specifiers
 * Return: Void
 */

void _printf(const char *format, ...)
{
	int index = 0
	int jindex;
	va_list arguments;

	f_call options[] = {
		{'c', printf_c},
		{'i', printf_i},
		{'f', printf_f},
		{'s', printf_str},
	};

	va_start(arguments, format);

	while (format && format[index]) /* while there's something to test */
	{
		jindex = 0;

		while (jindex < 4) /* while all of modulus hasn't been checked, check! */
		{
			if (format[index] == options[jindex].c) /* if match found */
			{
				options[jindex].f(arguments); /* modulus masking printf func */
				break; /* if found, break */
			}
			jindex++; /* if no match, check the next array in modulus */
		}
		index++; /* check the next specifier in format */
	}
	va_end(arguments); /* clear all + memory */
}
