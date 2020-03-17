#include "holberton.h"
#include <stdio.h>

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
 * print_R - replaces characters
 * in rot13 format
 * from leet into normal strings
 * @l: pointer string importing
 * from main
 * Return: Returns final value
 * into the pointer
 */

int printf_R(va_list list)
{
	char *l33t = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *real = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	int i;
	int j;
	char *str = va_arg(list, char *);
	char *capture;

	printf("Checking\n");
	for (i = 0; str[i] != '\0'; i++) /* while input != NULL char */
	{
		printf("Entering the loop %d \n", i);
		for (j = 0; j < 52; j++) /* 52 = chars in l33t */
		{
			printf("Entering j loop %d \n", j);
			if (str[i] == real[j]) /* try to match everything from str[i] with the real[j] by scanning with j */
			{
				printf("entered the if loop %d", j);
				capture[i] = l33t[j]; /* if found copy l33t[j] into capture[i] */
				_putchar(capture[i]); /*print out whatever was replaced */
				break; /* match found! break loop go back to i loop */
			}
		}
	}
return (i); /* record and report back on the strlen */
}

int printf_binary(va_list list)
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
		count++;
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
