#include "holberton.h"
#define ITS_A_DIGIT (***c >= '0' && ***c <= '9')

/**
 * getprinter - matches a format specifier & calls its related function
 * @in: pointer to input string
 * @out: pointer to out buffer
 * @list: imported list of arguments from function that called getprinter
 * Return: strlen of whatever string was printed
 **/
void getprinter(const char **in, char **out, va_list list)
{
	int i = 0;
	char *specs = "cboxXdiup", *str;
	config_t config = format_config(&in);

	for (i = 0; specs[i]; i++)
		if (specs[i] == **in)
		{
			config.arg = va_arg(list, unsigned long int);
			for (str = p_num(config); *str; (*out)++)
			{
				**out = *str;
				if (*(++str) == '\0')
					break;
			}
			return;
		}

	if (**in == 's')
	{
		config.str = va_arg(list, char *);
		for (str = p_s(config); *str; (*out)++)
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
config_t format_config(const char ***in)
{
	config_t config = {0};

	for (; 1; (**in)++)
		if (***in == '-')
			config.minus = true;
		else if (***in == '+')
			config.plus = true;
		else if (***in == ' ')
			config.space = true;
		else if (***in == '0')
			config.zero = true;
		else if (***in == '#')
			config.hash = true;
		else
			break;

	for (; ITS_A_DIGIT; (**in)++)
		config.width = (config.width * 10) + (***in - '0');

	if (***in == '.')
		for ((**in)++; ITS_A_DIGIT; (**in)++)
			config.precision = (config.precision * 10) + (***in - '0');

	if (***in == 'l')
	{
		config.longint = true;
		(**in)++;
	}
	else if (***in == 'h')
	{
		config.shortint = true;
		(**in)++;
	}

	config.spec = ***in;

	return (config);
}

/**
 * p_s - prints a string
 * @settings: void
 * Return: formatted string
 **/
char *p_s(config_t settings)
{
	char *str = config.str, *p = "(null)";
	size_t len = _strlen(str);
	int i = 0;

	(void)settings;

	if (str)
		for (p = malloc(len); str[i]; i++)
			p[i] = str[i];

	return (p);
}
