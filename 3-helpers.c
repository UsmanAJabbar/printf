#include "holberton.h"

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
 * _strdup - duplicates a string
 * @s: string
 * Return: malloc'd duplicate of string
 **/
char *_strdup(char *s)
{
	char *tmp;
	int i;

	if (s == NULL)
		return (_strdup("(null)"));

	tmp = malloc(_strlen(s) + 1);
	if (tmp == NULL)
		return (NULL);
	for (i = 0; s[i]; i++)
		tmp[i] = s[i];

	tmp[i] = '\0';

	return (tmp);
}

/**
* _strchr - locates a character in a string
* @s: string to be searched
* @c: character to be located
* Return: pointer to first occurence of c | NULL if c not found
**/
char *_strchr(char *s, char c)
{
	while (*s)
		if (*s++ == c)
			return (s);
	return (NULL);
}

/**
 * new_str_list_node - creates a new strlist node
 * Return: new node
 **/
str_list *new_str_list_node(void)
{
	str_list *f = malloc(sizeof(str_list));

	if (f == NULL)
		return (NULL);

	f->str = NULL;
	f->type = 0;
	f->len = 0;
	f->minus = 0;
	f->plus = 0;
	f->space = 0;
	f->zero = 0;
	f->hash = 0;
	f->has_min = 0;
	f->width = 0;
	f->has_max = 0;
	f->precision = 0;
	f->next = NULL;

	return (f);
}

/**
 * free_strlist - frees all contents in a str list
 * @h: head of list
 * Return: void
 **/
void free_strlist(str_list *h)
{
	str_list *tmp;

	while (h)
	{
		free(h->str);
		tmp = h;
		h = h->next;
		free(tmp);
	}
}
