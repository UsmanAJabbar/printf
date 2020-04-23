#include "holberton.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * getprinter - matches a format specifier & calls its related function
 * @c: character that represents the desired format specifier to find
 * @args: imported list of arguments from function that called getprinter
 * Return: strlen of whatever string was printed
 **/
int getprinter(char c, va_list args)
{
	int i = 0, j = 1;
	f_str str[] = {
		{'c', p_c},
		{'s', p_s},
		{'r', p_r},
		{'R', p_R},
		{'S', p_S},
		{'p', p_p},
	};
	f_num num[] = {{'b', 1, 0}, {'o', 3, 0}, {'x', 4, 39}, {'X', 4, 7}};

	if (c == 'u' || c == 'd' || c == 'i')
		return (p_int(c, va_arg(args, int)));

	for (; i < 6; i++)
		if (c == str[i].c)
			return (str[i].f(args));

	for (i = 0; i < 4; i++)
		if (c == num[i].c)
			return (p_num(num[i], va_arg(args, int)));

	if (c != '%')
		j -= _putchar('%');
	return (_putchar(c) - j);
}

/**
 * p_c - prints a character
 * @list: imported argument list containing char
 * Return: 0
 */
int p_c(va_list list)
{
	_putchar(va_arg(list, int));
	return (0);
}

/**
 * p_s - prints a string
 * @list: imported argument list containing string
 * Return: strlen
 */
int p_s(va_list list)
{
	int len = -1;
	char *str = va_arg(list, char *);

	if (str == NULL)
		len += write(1, "(null)", 6);
	else
		for (; *str; len++)
			_putchar(*str++);

	return (len);
}

/**
 * p_int - prints integers
 * @c: format specifier. determines behavior of function
 * @n: integer to be printed
 * Return: strlen
 */
int p_int(char c, unsigned int n)
{
	int len = -1;
	unsigned int last_pos = INT_MAX;

	if (n > last_pos && c != 'u')
	{
		len += _putchar('-');
		n = -n;
	}

	if (n > 9)
		return (p_int(c, n / 10) + _putchar('0' + n % 10));

	return (len + _putchar(n + '0'));
}
