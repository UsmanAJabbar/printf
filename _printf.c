#include "holberton.h"

/**
 * _printf- acts a printf function
 * @s: string to be printed
 * Return: string length or -1 if failed
 */
int _printf(const char *s, ...)
{
	int len = -1;
	va_list args;

	va_start(args, s);

	if (s)
		for (len = 0; *s; len++, s++)
			if (*s == '%')
				if (*++s)
					len += getprinter(*s, args);
				else
					return (-1);
			else
				_putchar(*s);
	va_end(args);
	return (len);
}

/**
 * getprinter - matches a format specifier & calls its related function
 * @c: character that represents the desired format specifier to find
 * @args: imported list of arguments from function that called getprinter
 * Return: 0 if match found, -1 if match not found
 **/
int getprinter(char c, va_list args)
{
	int i = 0, j = 1;
	f_call options[] = {
		{'c', printf_c},
		{'s', printf_str},
		{'d', printf_i_d},
		{'i', printf_i_d},
		{'r', printf_r},
		{'R', printf_R},
		{'b', printf_b},
	};

	for (; i < 7; i++)
		if (c == options[i].c)
			return (options[i].f(args));

	if (c != '%')
		j -= _putchar('%');
	return (_putchar(c) - j);
}
