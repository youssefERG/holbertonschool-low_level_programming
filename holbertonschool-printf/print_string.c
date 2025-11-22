#include "holberton.h"

/**
 * print_string - prints a string (specifier %s)
 * @ap: va_list containing (char *)
 *
 * Return: number of bytes printed, or -1 on error
 */
int print_string(va_list ap)
{
	char *s = va_arg(ap, char *);
	int len = 0;

	if (s == NULL)
		s = "(null)";

	while (s[len])
		len++;

	if (len == 0)
		return (0);

	return (_write_buf(s, len));
}
