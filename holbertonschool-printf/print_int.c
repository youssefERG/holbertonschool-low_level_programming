#include "holberton.h"

/**
 * print_int - prints an integer (specifier %d and %i)
 * @ap: va_list containing int
 *
 * Return: number of bytes printed, or -1 on error
 *
 * Notes: Uses long and unsigned long to avoid overflow on INT_MIN.
 */
int print_int(va_list ap)
{
	long n = (long)va_arg(ap, int);
	char buf[32];
	int i = 0, len = 0;
	unsigned long val;

	if (n < 0)
	{
		if (_putchar('-') < 0)
			return (-1);
		len++;
		/* safe conversion for INT_MIN */
		val = (unsigned long)(-(n + 1)) + 1UL;
	}
	else
		val = (unsigned long)n;

	if (val == 0)
		buf[i++] = '0';
	while (val > 0)
	{
		buf[i++] = '0' + (val % 10);
		val /= 10;
	}

	while (i-- > 0)
	{
		if (_putchar(buf[i]) < 0)
			return (-1);
		len++;
	}

	return (len);
}
