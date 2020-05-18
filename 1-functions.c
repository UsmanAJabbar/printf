#include "holberton.h"
#define ITS_A_DIGIT (**in >= '0' && **in <= '9')

/**
 * getprinter - matches a format specifier & calls its related function
 * @in: pointer to input string
 * @out: pointer to out buffer
 * @list: imported list of arguments from function that called getprinter
 * Return: strlen of whatever string was printed
 **/
void getprinter(const char **in, char **out, va_list list)
{
	char *specs = "cboxXdiup", *str;
	format f = format_config(in);

	while (*specs)
		if (*specs++ == **in)
		{
			f.arg = va_arg(list, unsigned long int);
			for (str = p_num(f); *str; (*out)++)
			{
				**out = *str;
				if (*(++str) == '\0')
					break;
			}
			return;
		}

	if (**in == 's')
	{
		f.str = va_arg(list, char *);
		for (str = p_s(f); *str; (*out)++)
		{
			**out = *str;
			if (*(++str) == '\0')
				break;
		}
		return;
	}

	**out = '%';
	if (**in != '%')
	{
		(*out)++;
		**out = **in;
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

/**
 * p_s - prints a string
 * @f: void
 * Return: formatted string
 **/
char *p_s(format f)
{
	char *str = f.str, *p = "(null)";
	size_t len = _strlen(str);
	int i = 0;

	if (str)
		for (p = malloc(len); str[i]; i++)
			p[i] = str[i];

	return (p);
}
