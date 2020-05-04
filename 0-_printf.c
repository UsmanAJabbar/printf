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

	for (len = 0; s && *s; len++, s++)
		if (*s == '%')
			if (*++s)
				len += getprinter(&s, args);
			else
				return (-1);
		else
			_putchar(*s);
	va_end(args);
	return (len);
}
