#include "holberton.h"
/**
 * format_numconfig - returns a numconfig struct
 * @c: format specifier to match with numconfig struct
 * Return: num_t struct
 */
num_t *format_numconfig(char c)
{
	num_t *num = NULL;
	num_t nums[] = {
		{'b', 1, 0},
		{'o', 3, 0},
		{'x', 4, 39},
		{'X', 4, 7},
		{'p', 4, 39},
	};
	int i;

	for (i = 0; i < 5; i++)
		if (nums[i].spec == c)
			num = &nums[i];

	return (num);
}
/**
 * p_num - prints numbers, addresses, and single chars
 * @config: config struct with algorithm configurations
 * Return: formatted str
 */
char *p_num(config_t config)
{
	num_t *num = format_numconfig(config.spec);
	unsigned long int n = config.arg;
	int i, ck, print = 0, bits = 32;
	char buf[1024], *p = buf;

	if (num == NULL)
		return (p_uidc(config));

	for (i = 0; i < 1024; i++)
		buf[i] = 0;

	if (config.spec == 'p')
	{
		*p++ = '0';
		*p++ = 'x';
	}

	if (config.longint || config.spec == 'p')
		bits *= 2;

	while (bits)
	{
		for (i = 0, ck = 1; ck; ck = bits % num->power)
			i = (i << 1) + ((n >> --bits) & 1);
		if (i > 9)
			i += num->hex_char;
		if (!print)
			print = (i & 15);
		if (print)
			*p++ = i + '0';
	}

	if (n == 0)
		*p = i + '0';

	p = buf;

	return (p);
}

/**
 * p_uidc - prints chars and base-10 integers
 * @config: config struct with algorithm configurations
 * Return: formatted str
 */
char *p_uidc(config_t config)
{
	unsigned long int n = config.arg, max = INT_MAX, i, size = 1, print;
	char spec = config.spec, buf[20], *p = buf;

	for (i = 0; i < 20; i++)
		buf[i] = 0;

	if (spec == 'c')
	{
		*p = n;
		return (p);
	}

	if (spec == 'u')
		max = UINT_MAX;

	if (n > max && config.longint == 0)
	{
		if (spec == 'u')
		{
			n -= UINT_MAX;
			n -= 1;
		}
		else
		{
			*p++ = '-';
			n = ~(n - 1) & UINT_MAX;
		}
	}

	for (i = n, print = 0, size = 1000000000000000000; size; size /= 10)
	{
		if (i / size == 0 && print == 0)
			continue;
		print = 1;
		*(p++) = (i / size) + '0';
		i %= size;
	}

	p = buf;
	return (p);
}
