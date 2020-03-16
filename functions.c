#include "holberton.h"

/**
 * printf_c - prints a character
 *
 * @list: imported argument list
 *
 * Return: 0
 */
int printf_c(va_list list)
{
	_putchar(va_arg(list, int));
	return (0);
}

/**
 * printf_str - prints a string daddy
 *
 * @list: imported argument list
 *
 * Return: strlen
 */

int printf_str(va_list list)
{
	int index; /* prints the numbers */
	int count = -1; /* captures the strlen */
	char *str = va_arg(list, char *);

	for (index = 0; str[index] != '\0'; index++)
	{
		_putchar(str[index]);
		count++;
	}
	return (count);
}

/**
 * printf_i_d - prints numbers
 * @list: va_list
 * Return: strlen
 */

int printf_i_d(va_list list)
{
	int temp;
	int size = 1;
	int count = -1;
	int n = va_arg(list, int);

	/* check if its INT_MIN as edge case */
	if (n == -2147483648)
	{
		_putchar('-');
		_putchar('2');
		n = n % 1000000000;
		n = -n;
	}

	/* if input is negative, postive it */
	/* manually print the '-' sign */
	if (n < 0)
	{
		_putchar('-');
		n = -n;
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
		count++;
	}
	return (count);
}
