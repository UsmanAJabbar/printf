#include "holberton.h"

/**
 * p_s - prints a string
 * @list: arguments list`
 * @f: void
 * Return: formatted string
 **/
char *p_s(va_list list, str_list *f)
{
	char *tmp;

	if (f->type == 'c')
		return (p_c(va_arg(list, int), NULL));

	tmp = _strdup(va_arg(list, char *));

	if (f->type == 's' || tmp == NULL)
		return (tmp);

	if (f->type == 'r')
		return (rev_string(tmp));

	if (f->type == 'R')
		return (rot13(tmp));

	return (p_S(tmp));
}

/**
 * p_S - replaces non-printable chars with a hex-output of ASCII code
 * @s: string
 * Return: new string
 **/
char *p_S(char *s)
{
	int i = 0, j, k, num_of_non_printable_chars = 0;
	char *tmp;

	for (; s[i]; i++)
		if (s[i] < 32 || s[i] > 126)
			num_of_non_printable_chars++;

	tmp = malloc(i + 3 * num_of_non_printable_chars + 1);

	if (tmp == NULL)
		return (NULL);

	for (i = 0, j = 0; s[j]; i++, j++)
		if (s[j] < 32 || s[j] > 126)
		{
			tmp[i++] = '\\';
			tmp[i++] = 'x';
			tmp[i++] = (s[j] / 16) + '0';
			k = (s[j] % 16) + '0';
			tmp[i] = k;
			if (k > '9')
				tmp[i] += 7;
		}
		else
			tmp[i] = s[j];

	tmp[i] = '\0';
	free(s);
	return (tmp);
}

/**
 * rot13 - rot13's a string
 * @s: string to turn into rot13 format
 * Return: string length
 **/
char *rot13(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		if (is_alpha(s[i]))
		{
			if (s[i] >= 'n' || (s[i] >= 'N' && s[i] <= 'Z'))
				s[i] -= 13;
			else
				s[i] += 13;
		}

	return (s);
}

/**
 * rev_string - reverses a string
 * @s: string to reverse
 * Return: string length
 **/
char *rev_string(char *s)
{
	int i = 0, j = _strlen(s) - 1;
	char tmp;

	while (i != j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		if (++i == j--)
			break;
	}

	return (s);
}

/**
 * p_mod - prints a '%' sign
 * @list: void
 * @f: void
 * Return: '%' as a malloc'd string
 **/
char *p_mod(va_list list, str_list *f)
{
	char *arg = malloc(2);

	(void)list;
	(void)f;
	if (arg == NULL)
		return (NULL);
	arg[0] = '%';
	arg[1] = '\0';
	return (arg);
}
