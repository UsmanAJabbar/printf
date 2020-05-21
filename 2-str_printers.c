#include "holberton.h"

/**
 * p_s - prints a string
 * @f: void
 * @list: arguments list`
 * Return: formatted string
 **/
char *p_s(format f, va_list list)
{
	char *s = va_arg(list, char *);
	char *p = malloc(sizeof(char) * _strlen(s) + 1);
	char *alt = "(null)";

	if (s == NULL)
		return (append("(null)", &p, ""));

	if (f.spec == 'r')
		return (append_rev(s, &p));
	else if (f.spec == 'R')
		return (append_rot13(s, &p));
	else
		return (append(s, &p, alt));
}

/**
 * append_rot13 - appends a rot13'd string to a buffer
 * @s:      string to append to...
 * @buf:    ...buffer
 * Return: address of beginning of string
 **/
char *append_rot13(char *s, char **buf)
{
	int rot = 13;
	char *head = s;

	for (; *s; rot = 13)
	{
		if (*s >= 'a' && *s <= 'z')
		{
			if (*s >= 'n')
				rot = -rot;
			*(*buf)++ = *s++ + rot;
		}
		else if (*s >= 'A' && *s <= 'Z')
		{
			if (*s >= 'N')
				rot = -rot;
			*(*buf)++ = *s++ + rot;
		}
		else
		{
			*(*buf)++ = *s++;
		}
	}

	return (head);
}

/**
 * append - appends a string to a buffer
 * @s:      string to append to...
 * @buf:    ...buffer
 * @alt:    alternate string (if s is NULL)
 * Return: address of beginning of string
 **/
char *append(char *s, char **buf, char *alt)
{
	char *head = *buf;

	if (s == NULL)
		return (append(alt, buf, ""));

	while (*s)
		*(*buf)++ = *s++;

	**buf = *s;

	return (head);
}

/**
 * append_rev - appends a string in reverse to a buffer
 * @s:      string to reverse and append to..
 * @buf:    ...buffer
 * Return: address of beginning of string
 **/
char *append_rev(char *s, char **buf)
{
	char *p = s, *head = *buf;

	while (*p)
		p++;

	while (--p != s)
		*(*buf)++ = *p;
	*(*buf)++ = *s;

	return (head);
}
