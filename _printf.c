#include <stdarg.h>
#include "holberton.h"
#include <stdio.h>
/**
 * print_all - acts a printf function
 * @format: contains specifiers
 * Return: Void
 */

void _printf(const char *format, ...)
{
	int index = 0;
	int jindex;
	va_list arguments;

	f_call options[] = {
		{'c', printf_c},
		/*{'i', printf_i},
		{'f', printf_f},*/
		{'s', printf_str},
	};

	va_start(arguments, format);

	while (format && format[index]) /* while there's something to test */
	{
		if (format[index] == '%')
		{
			index++; /* Let's go check what the next character is */

			if (format[index] == '%')	/* If the next char is a percent... */
			{
				_putchar('%');		/* print it! */
			}
			else				/* else... */
			{
				jindex = 0;

				while (jindex < 2)
				{
					/**
					* If the next char is equal to the char
					* of one of the structs in options[], then use
					* the function associated with that char.
					*/
					if (format[index] == options[jindex].c)
					{
						options[jindex].f(arguments);
					}

					jindex++;
				}
			}
		}
		/*else if (format[index] == '\')
		{
		}*/
		else
		{
			_putchar(format[index]);
		}
	index++;

	}
	va_end(arguments); /* clear all + memory */
}
