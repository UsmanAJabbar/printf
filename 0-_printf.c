#include "holberton.h"
#define MEM_BLOCK 1024
/**
 * _printf- acts a printf function
 * @in: string to be printed
 * Return: string length or -1 if failed
 */
int _printf(const char *in, ...)
{
	va_list args;
	char out[MEM_BLOCK], *p;
	int i;

	if (in == NULL)
		return (-1);

	for (i = 0; i < MEM_BLOCK; i++)
		out[i] = 0;

	va_start(args, in);

	for (p = out; *in; in++, p++)
		if (*in == '%')
			if (*(++in))
				getprinter(&in, &p, args);
			else
				return (-1);
		else
			*p = *in;

	va_end(args);

	return (write(1, out, _strlen(out)));
}

/**
 * _strlen - length of string
 * @s: string
 * Return: length
 **/
size_t _strlen(char *s)
{
	size_t len = 0;

	while (s && *s)
		len++, s++;

	return (len);
}
