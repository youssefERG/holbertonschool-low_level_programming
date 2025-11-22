#include "holberton.h"

/**
 * print_char - prints a single character (specifier %c)
 * @ap: va_list containing the char (promoted to int)
 *
 * Return: number of bytes printed (1) or -1 on error
 */
int print_char(va_list ap)
{
	char c = (char)va_arg(ap, int);

	return (_putchar(c));
}
