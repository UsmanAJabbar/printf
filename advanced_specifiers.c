#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
* printf_r - prints a string in reverse, followed by a new line.
* @list: string to be printed
* Return: temp
*/

int printf_r(va_list list)
{
	int count = 0;
	int temp;
	char *s = va_arg(list, char *);

	while (s[count])
		count++;

	temp = (count - 1);

	while (count--)
		_putchar(s[count]);

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
