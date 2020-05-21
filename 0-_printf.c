#include "holberton.h"
#define MEM_BLOCK 4096
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

	for (p = out; *in; in++)
		if (*in == '%')
			if (*(++in))
				getprinter(&in, &p, args);
			else
				return (-1);
		else
			*p++ = *in;

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

	if (s)
		while (s[len])
			len++;

	return (len);
}

/**
 * getprinter - matches a format specifier & calls its related function
 * @in: pointer to input string
 * @out: pointer to out buffer
 * @list: imported list of arguments
 * Return: void
 **/
void getprinter(const char **in, char **out, va_list list)
{
	char *s = NULL;
	printer ops[] = {{"cdiu", p_base10}, {"bopxX", p_num}, {"srR", p_s}};
	format f = format_config(in);
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; ops[i].codes[j]; j++)
			if (f.spec == ops[i].codes[j])
				s = append(ops[i].f(f, list), out, "");

	if (s == NULL)
	{
		if (**in != '%')
			*(*out)++ = '%';
		*(*out)++ = **in;
	}
}

/**
 * format_config - creates & returns config for format printer
 * @in: pointer to input string
 * Return: a filled out config struct
 **/
format format_config(const char **in)
{
	format f = {0};

	for (; 1; (*in)++)
		if (**in == '-')
			f.minus = true;
		else if (**in == '+')
			f.plus = true;
		else if (**in == ' ')
			f.space = true;
		else if (**in == '0')
			f.zero = true;
		else if (**in == '#')
			f.hash = true;
		else
			break;

	for (; ITS_A_DIGIT; (*in)++)
		f.width = (f.width * 10) + (**in - '0');

	if (**in == '.')
		for ((*in)++; ITS_A_DIGIT; (*in)++)
			f.precision = (f.precision * 10) + (**in - '0');

	if (**in == 'l')
	{
		f.len = 'l';
		(*in)++;
	}
	else if (**in == 'h')
	{
		f.len = 'h';
		(*in)++;
	}

	f.spec = **in;

	return (f);
}
