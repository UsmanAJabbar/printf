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
 * get_base - returns the base_s struct corresponding to c
 * @c: character to be matched with a base_s struct
 * Return: base_s struct
 **/
base_s get_base(char c)
{
	int i;
	base_s bases[] = {{'b', 1, 0}, {'o', 3, 0}, {'x', 4, 39}, {'X', 4, 7}};

	for (i = 0; bases[i].c != c; i++)
		;

	return (bases[i]);
}

/**
 * p_num - prints numbers
 * @vars: struct with variable values needed
 * @n: number to print.
 * Return: strlen
 */
int p_num(base_s vars, int n)
{
	int ck, tmp, print = 0, len = -1, bits = 32;

	if (vars.c == 'd' || vars.c == 'i' || vars.c == 'u')
		return (p_int(vars.c, n));

	while (bits)
	{
		for (tmp = 0, ck = 1; ck; ck = bits % vars.exp)
			tmp = (tmp << 1) + ((n >> --bits) & 1);

		if (!print)
			print = tmp & 15;

		if (tmp > 9 && print)
			len += _putchar(tmp + '0' + vars.hex);
		else if (print)
			len += _putchar(tmp + '0');
	}
	return (len);
}
