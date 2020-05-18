#include "holberton.h"
/**
 * num_config - returns a numconfig struct
 * @c: format specifier to match with numconfig struct
 * Return: num_t struct
 */
num_t *num_config(char c)
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
 * @f: config struct with algorithm configurations
 * Return: formatted str
 */
char *p_num(format f)
{
	num_t *num = num_config(f.spec);
	unsigned long int n = f.arg;
	int i, ck, print = 0, bits = 32;
	char buf[65], *p = buf;

	if (num == NULL)
		return (p_uidc(f));

	for (i = 0; i < 65; i++)
		buf[i] = 0;

	if (f.spec == 'p')
	{
		*p++ = '0';
		*p++ = 'x';
		bits = 64;
	}

	if (f.len == 1)
		bits = 64;

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
 * @f: config struct with algorithm configurations
 * Return: formatted str
 */
char *p_uidc(format f)
{
	unsigned long int n = f.arg, max = get_max(f.spec, f.len),
					  print = 0, i, size = 1E19, negafier = UINT_MAX;
	char buf[21], *p = buf;

	for (i = 0; i < 21; i++)
		buf[i] = 0;

	if (f.spec == 'c')
	{
		*p = n;
		return (p);
	}

	p = buf;
	if (max > negafier)
		negafier = ULONG_MAX;

	if (n > max)
	{
		*p++ = '-';
		n = ~(n - 1) & negafier;
	}

	for (; size; size /= 10)
	{
		if ((n / size) || print || size == 1)
		{
			print = 1;
			*(p++) = (n / size) + '0';
			n %= size;
		}
	}

	p = buf;
	return (p);
}
/**
 * get_max - get max value
 * @spec: format specifier
 * @len: format length type
 **/
unsigned long int get_max(int spec, int len)
{
	if (spec == 'u')
	{
		if (len == 'l')
			return (ULONG_MAX);

		if (len == 'h')
			return (USHRT_MAX);

		return (UINT_MAX);
	}

	if (len == 'l')
		return (LONG_MAX);

	if (len == 'h')
		return (SHRT_MAX);

	return (INT_MAX);
}