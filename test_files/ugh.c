#include "holberton.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int main ()
{
	int len;
	int i = INT_MIN;
	len = printf("#max: %d\n", i);
	printf("#len = %d\n", len);
	len = _printf("_max: %d\n", i);
	printf("_len = %d\n", len);
	return 0;
}
