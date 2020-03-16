#include <stdarg.h>
#include "holberton.h"
#include <stdio.h>
/**
 * _printf- acts a printf function
 * @format: string to be printed
 * Return: string length (after accounting for specifiers)
 */

int _printf(const char *format, ...)
{
	int index = 0;
	int jindex;
	va_list arguments;
	int char_count = 0;

	f_call options[] = {
		{'c', printf_c},
		{'s', printf_str},
	};

	va_start(arguments, format);

	while (format && format[index])			/* while there's something to test */
	{
		if (format[index] == '%')
		{
			index++;			/* Let's go check what the next character is */
			if (format[index] == '%')	/* If the next char is a percent... */
				_putchar('%');		/* print it! */
			else				/* else... */
			{
				jindex = 0;
				while (jindex < 2)
				{
					if (format[index] == options[jindex].c)
					{
						options[jindex].f(arguments);
						break;
					}
					jindex++;
				}
				if (jindex == 2)
					return (-1);
			}
		}
		else
		{
			_putchar(format[index]);
		}
	index++;
	char_count++;
	}
	va_end(arguments);				/* clear all + memory */
	return (char_count);
}
