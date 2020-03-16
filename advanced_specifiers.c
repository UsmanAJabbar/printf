#include "holberton.h"

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
