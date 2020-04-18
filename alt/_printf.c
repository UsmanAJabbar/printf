#include "holberton.h"

/**
 * _printf- acts a printf function
 * @s: string to be printed
 * Return: string length or -1 if failed
 */
int _printf(const char *s, ...)
{
	int len = 0;
	va_list args;

	va_start(args, s);

	for (; *s; len++, s++)
		if (*s == '%')
			len += getprinter(*++s, args);
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
 */
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

/**
 * confirm_print - identifies any unprintable format specifiers
 * @s: the string to check for unprintable specifiers
 * Return: -1 if error found, 0 if string is safe to print
 */
int confirm_print(const char *s)
{
	int i = 0, j = 0, check = 0;
	char *okays = "csdirRb%";

	for (; s && s[i] && !check; i++)
		if (s[i] == '%')
			for (j = 0, i++, check++; okays[j] && check; j++)
				if (okays[j] == s[i])
					check--;

	return (check);
}
