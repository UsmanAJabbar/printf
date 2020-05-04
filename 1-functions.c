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
int getprinter(const char **c, va_list args)
{
	int i = 0, j = 1, l = 0;
	f_str str[] = {
		{'c', p_c},
		{'s', p_s},
		{'r', p_r},
		{'R', p_R},
		{'S', p_S},
		{'p', p_p},
	};
	f_num num[] = {{'b', 1, 0}, {'o', 3, 0}, {'x', 4, 39}, {'X', 4, 7}};

	for (; i < 6; i++)
		if (**c == str[i].c)
			return (str[i].f(args));

	if (**c == 'l')
		l++, (*c)++;

	if (**c == 'u' || **c == 'd' || **c == 'i')
	{
		if (*(*c - 1) == 'l')
			return (p_long(**c, va_arg(args, unsigned long int)));
		else
			return (p_int(**c, va_arg(args, unsigned int)));
	}

	for (i = 0; i < 4; i++)
		if (**c == num[i].c)
			return (p_num(num[i], va_arg(args, unsigned long int), l));

	if (**c != '%')
		j -= _putchar('%');
	return (_putchar(**c) - j);
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
	int neg = 0;
	unsigned int last_pos = INT_MAX;

	if (n > last_pos && c != 'u')
	{
		neg += _putchar('-');
		n = -n;
	}

	if (n > 9)
		return (neg + p_int(c, n / 10) + _putchar('0' + n % 10));

	return (neg + _putchar(n + '0') - 1);
}
