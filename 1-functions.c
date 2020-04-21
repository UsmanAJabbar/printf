#include "holberton.h"

/**
 * getprinter - matches a format specifier & calls its related function
 * @c: character that represents the desired format specifier to find
 * @args: imported list of arguments from function that called getprinter
 * Return: 0 if match found, -1 if match not found
 **/
int getprinter(char c, va_list args)
{
	int i = 0, j = 1;
	f_str strings[] = {{'c', p_c}, {'s', p_s}, {'r', p_r}, {'R', p_R}};
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
 * printf_c - prints a character
 * @list: imported argument list
 * Return: 0
 */
int p_c(va_list list)
{
	_putchar(va_arg(list, int));
	return (0);
}

/**
 * printf_str - prints a string
 * @list: imported argument list
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
 * printf_num - prints numbers
 * @list: va_list
 * Return: strlen
 */
int p_num(char c, int n)
{
	int i, j, base = 0, hex = 0, len = 0;
	base_t bases[] = {{'b', 1}, {'o', 3}, {'x', 4}, {'X', 4}};

	/*printf("\n\tn = %d", n);*/

	if (c == 'd' || c == 'i' || c == 'u')
		return (p_int(c, n));

	for (i = 0; !base; i++)
		if (bases[i].c == c)
			base = bases[i].base;

	if (c == 'x')
		hex = 39;
	if (c == 'X')
		hex = 7;

	if (n < 0 && c == 'b')
	{
		if (n == -1)
			len = _putchar('1');
		for (i = 0, j = -1; j * 2 >= n; i++, j *= 2)
			if (n == j * 2)
				len += _putchar('1');

		for (j = i; j < 30; j++)
			len += _putchar('1');

		n = -n;
	}

	if (n != 1 && n != 0 && n != -1 && n >> base)
		len = p_num(c, n >> base);

	for (i = 0, j = 0; i < base; i++)
		j += n & (1 << i);

	if (j > 9)
		return (_putchar(j + '0' + hex) + len);

	return (_putchar(j + '0') + len);
}

/**
 * p_int - prints integers
 * @list: va_list
 * Return: strlen
 */
int p_int(char c, int n)
{
	int temp;
	int size = 1;
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
	/* if input is negative, postive it */
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
