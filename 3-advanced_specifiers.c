#include "holberton.h"

/**
 * p_long - prints long integers
 * @c: format specifier. determines behavior of function
 * @n: integer to be printed
 * Return: strlen
 */
int p_long(char c, unsigned long int n)
{
	int neg = 0;
	unsigned long int last_pos = LONG_MAX;

	if (n > last_pos && c != 'u')
	{
		neg += _putchar('-');
		n = -n;
	}

	if (n > 9)
		return (neg + p_int(c, n / 10) + _putchar('0' + n % 10));

	return (neg + _putchar(n + '0') - 1);
}
