#include "holberton.h"

/**
* p_r - prints a string in reverse, followed by a new line.
* @list: arguments list containing string to be printed
* Return: strlen
*/

int p_r(va_list list)
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
 * p_R - replaces characters in rot13 format
 * @list: imported argument list
 * Return: strlen
 */

int p_R(va_list list)
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
 * p_num - prints numbers
 * @c: format specifier. determines behavior of function.
 * @n: number to print.
 * Return: strlen
 */
int p_num(char c, int n)
{
	int i, j, base = 0, hex = 0, len = 0;
	base_s bases[] = {{'b', 1}, {'o', 3}, {'x', 4}, {'X', 4}};

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
