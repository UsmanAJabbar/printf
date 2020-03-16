#include "holberton.h"

void printf_c(va_list list)
{
	_putchar(va_arg(list, int));
}

void printf_str(va_list list)
{
	int i = 0;
	char *str = va_arg(list, char *);

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
