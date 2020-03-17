#include <stdarg.h>
#include "holberton.h"
#include <stdlib.h>
/**
 * _printf- acts a printf function
 * @format: string to be printed
 * Return: string length or -1 if failed
 */

int _printf(const char *format, ...)
{
	int index = 0;
	int len_f = 0;
	int strlen = 0;
	int error_check;
	va_list arguments;

	va_start(arguments, format);

	/* Use confirm_print func to check for errors. */
	error_check = confirm_print(format);
	if (error_check == -1)
		return(-1);

	while (format && format[index])			/* while there's something to test */
	{
		if (format[index] == '%')		/* check if the char is a % */
		{
			index++;			/* if so, check what the next char is */
			if (format[index] == '%')	/* If the next char is a percent... */
				_putchar('%');		/* print it! */
			/**
			 * else, identify the format specifier
			 * and use the corresponding printing function
			 */
			else
				len_f += get_printer(format[index], arguments);
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
		{'R', printf_R},
	};

	while (i < 6)
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

/**
 * confirm_print - identifies any unprintable format specifiers
 *
 * @format: the string to check for unprintable specifiers
 *
 * Return: -1 if error found, 0 if format is safe to print
 */
int confirm_print(const char *format)
{
	int index = 0;
	int jindex = 0;
	char *specifier = "csdirR%";
	int percent_check = 0;

	if (format == NULL)
		return (-1);

	if (!(format || format[index]))			/* if string is empty or null, return 0 */
		return (0);

	while (format && format[index])			/* while there's something to test...*/
	{
		if (format[index] == '%')		/* check if the char is a % */
		{
			index++;
			percent_check++;
			/**
			 * if so, go to the next char and check if its
			 * one of our approved format specifiers.
			 * Once a match is found, return 0
			 */
			jindex = 0;
			while (specifier && specifier[jindex])
			{
				if (specifier[jindex] == format[index])
					return (0);
				jindex++;
			}
		}

		index++;
	}
	/* If no matches were found, return -1 */
	if (percent_check != 0)
		return (-1);
	return (0);
}
