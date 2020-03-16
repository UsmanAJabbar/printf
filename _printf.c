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
	int len_f = 0;
	int strlen = 0;
	va_list arguments;

	va_start(arguments, format);

	while (format && format[index])			/* while there's something to test */
	{
		if (format[index] == '%')		/* check if the char is a % */
		{
			index++;			/* if so, check what the next char is */
			if (format[index] == '%')	/* If the next char is a percent... */
				_putchar('%');		/* print it! */
			else				/* else, we have a format specifier, so... */
			{
				/**
				 * ... call get_printer to identify the format specifier
				 * and pick/use the corresponding printing function;
				 * get_printer returns -1 if it found no match. In which case, return -1.
				 */
				len_f = get_printer(format[index], arguments);
				if (len_f == -1)
					return (-1);
			}
		}
		else
		{
			_putchar(format[index]);
		}
	index++;
	strlen++;
	}
	va_end(arguments);				/* clear all + memory */
	return (strlen + len_f);
}

/**
 * get_printer - identifies a format specifier & calls its related print func
 *
 * @c: character that represents the desired format specifier to find
 * @arguments: imported list of arguments from function that called get_printer
 *
 * Return: 0 if match found, -1 if match not found
 */

int get_printer(char c, va_list arguments)
{
	int i = 0;
	int strlen = 0;
	f_call options[] = {
		{'c', printf_c},
		{'s', printf_str},
		{'d', printf_i_d},
		{'i', printf_i_d},
		{'r', printf_r},
	};

	while (i < 5)
	{
		if (c == options[i].c)
		{
			strlen = options[i].f(arguments);
			return (strlen);
		}
		i++;
	}
	return (-1);
}
