#include "holberton.h"

/**
* p_S - prints ONLY characters in a string.
*		non-printable chars are printed as \x$ASCIIVALUE
* @list: arguments list containing string to be printed
* Return: strlen
*/

int p_S(va_list list)
{
	int len = -1;
	char *str = va_arg(list, char *);
	f_num num_vars = {'S', 4, 7};

	printf("printing S!\n");

	if (str == NULL)
		len += write(1, "(null)", 6);
	else
		for (; *str; len++, str++)
		{
			if (*str > 31 && *str < 127)
			{
				_putchar(*str);
			}
			else
			{
				_putchar('\\');
				len += _putchar('x');
				len += 1 + p_num(num_vars, (int)(*str));
			}
		}
	return (len);
}

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

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j < 95; j++)
		{
			if (str[i] == real[j])
			{
				if (str[i] == real[j])
					capture[i] = l33t[j];
				else
					capture[i] = symbols[j];
				_putchar(capture[i]);
				break;
			}
		}
	}
	free(capture);
	i--;
	return (i); /* record and report back on the strlen */
}

/**
 * p_num - prints numbers
 * @vars: struct with variable values needed
 * @n: number to print.
 * Return: strlen
 */
int p_num(f_num vars, unsigned long int n)
{
	int ck, tmp, print = 0, len = -1, bits = 32;

	if (vars.c == 'p')
		bits *= 2;

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
	if (len == -1)
		len += _putchar(tmp + '0');
	return (len);
}

/**
 * p_p - print a datum's address
 * @list: imported arguments list
 * Return: strlen
 **/
int p_p(va_list list)
{
	long int n = va_arg(list, long int);
	f_num num_vars = {'p', 4, 39};

	if (!n)
		return (write(1, "(nil)", 5) - 1);

	_putchar('0');
	_putchar('x');
	return (2 + p_num(num_vars, n));
}
