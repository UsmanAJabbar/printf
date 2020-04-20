#include "holberton.h"

/**
* printf_r - prints a string in reverse, followed by a new line.
* @list: string to be printed
* Return: temp
*/

int printf_r(va_list list)
{
	int len = 0, temp;
	char *s = va_arg(list, char *);

	while (s[len])
		len++;

	temp = (len - 1);

	while (len--)
		_putchar(s[len]);

	return (temp);
}

/**
 * printf_R - replaces characters in rot13 format
 *
 * @list: imported argument list
 *
 * Return: Returns
 */

int printf_R(va_list list)
{
	char *l33t = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *real = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	int i;
	char *symbols = " !.,<>/?;:[{]}`~@#$%^&*()-_=+'1234567890\"\\";
	int j;
	char *str = va_arg(list, char *);
	char *capture;

	capture = malloc(512);

	if (capture == NULL)
		exit(1);

	for (i = 0; str[i] != '\0'; i++) /* while input != NULL char */
	{
		for (j = 0; j < 95; j++) /* 52 = chars in l33t */
		{
			if (str[i] == real[j])
			{
				if (str[i] == real[j])
					capture[i] = l33t[j];
				else
					capture[i] = symbols[j]; /* if found copy l33t[j] into capture[i] */
				_putchar(capture[i]);
				break; /* match found! break loop go back to i loop */
			}
		}
	}
	free(capture);
	i--;
	return (i); /* record and report back on the strlen */
}

/**
 * printf_b - store number to print in binary
 * @list: va_list
 * Return: strlen
 */
int printf_b(va_list list)
{
	int n = va_arg(list, int);
	int i = 0, count = 0, tmp = -1;

	if (n < 0)
	{
		for (; tmp * 2 >= n; i++, tmp *= 2)
			if (n == tmp * 2)
			{
				_putchar('1');
				count++;
			}

		for (tmp = i; tmp < 30; tmp++)
			_putchar('1');

		print_bin(n);
		return (30);
	}

	return (print_bin(n) - 1);
}

/**
 * print_bin - print number in binary recursively
 * @n: number to print in binary
 * Return: 1 + rest of calls to print whole num
 **/
int print_bin(int n)
{
	int strlen = 0;

	if (n != 1 && n != 0 && n != -1)
		strlen = print_bin(n >> 1);
	_putchar((n & 1) + '0');
	return (1 + strlen);
}
