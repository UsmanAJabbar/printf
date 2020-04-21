#include "holberton.h"

/**
 * getprinter - matches a format specifier & calls its related function
 * @c: character that represents the desired format specifier to find
 * @args: imported list of arguments from function that called getprinter
 * Return: strlen of whatever string was printed
 **/
int getprinter(char c, va_list args)
{
	int i = 0, j = 1;
	f_char strings[] = {{'c', p_c}, {'s', p_s}, {'r', p_r}, {'R', p_R}};
	char *nums = "diuboxX";

	for (; i < 4; i++)
		if (c == strings[i].c)
			return (strings[i].f(args));

	for (i = 0; nums[i]; i++)
		if (nums[i] == c)
			return (p_num(c, va_arg(args, int)));

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
int p_int(char c, int n)
{
	unsigned int temp;
	unsigned int size = 1;
	int len = -1;

	/* check if its INT_MIN as edge case */
	if (n == -2147483648)
	{
		_putchar('-');
		_putchar('2');
		n = n % 1000000000;
		n = -n;
		len++;
		len++;
	}
	/* if input is negative, positive it */
	/* manually print the '-' sign */
	if (n < 0 && c != 'u')
	{
		_putchar('-');
		n = -n;
		len++;
	}

	temp = n;
	/* calculate the # of digits of n */
	while (temp / 10 != 0)
	{
		temp = temp / 10;
		size = size * 10;
	}
	/* print digits one at a time from start */
	for (; size > 0; size /= 10)
	{
		temp = n / size;
		_putchar(temp + '0');
		n = n % size;
		len++;
	}
	return (len);
}

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
