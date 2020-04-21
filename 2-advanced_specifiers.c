#include "holberton.h"

/**
* printf_r - prints a string in reverse, followed by a new line.
* @list: string to be printed
* Return: temp
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
 * printf_R - replaces characters in rot13 format
 *
 * @list: imported argument list
 *
 * Return: Returns
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
 * printf_b - store number to print in binary
 * @list: va_list
 * Return: strlen
 */
/*int p_b(int n)
{
	int i = 0, tmp = -1, strlen = 0;

	if (n < 0)
	{
		if (n == -1)
			strlen = _putchar('1');
		for (; tmp * 2 >= n; i++, tmp *= 2)
			if (n == tmp * 2)
				strlen += _putchar('1');

		for (tmp = i; tmp < 30; tmp++)
			strlen += _putchar('1');

		n = -n;
	}

	if (n != 1 && n != 0 && n != -1)
		strlen = p_b(n >> 1);

	return (_putchar((n & 1) + '0') + strlen);
}*/
