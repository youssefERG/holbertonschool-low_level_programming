#include "holberton.h"

/**
 * _printf - simplified printf implementation for Holberton mandatory tasks
 * @format: format string
 *
 * Return: number of characters printed (excluding null byte) or -1 on error.
 * Supported: %c, %s, %%, %d, %i
 */
int _printf(const char *format, ...)
{
	va_list ap;
	const char *p;
	int total = 0;
	int r;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	p = format;

	while (*p)
	{
		if (*p != '%')
		{
			r = _putchar(*p);
			if (r < 0)
			{
				va_end(ap);
				return (-1);
			}
			total += r;
			p++;
			continue;
		}

		/* found '%' */
		p++;
		if (*p == '\0') /* trailing '%' -> error */
		{
			va_end(ap);
			return (-1);
		}

		if (*p == 'c')
		{
			r = print_char(ap);
			if (r < 0) { va_end(ap); return (-1); }
			total += r;
		}
		else if (*p == 's')
		{
			r = print_string(ap);
			if (r < 0) { va_end(ap); return (-1); }
			total += r;
		}
		else if (*p == '%')
		{
			r = print_percent();
			if (r < 0) { va_end(ap); return (-1); }
			total += r;
		}
		else if (*p == 'd' || *p == 'i')
		{
			r = print_int(ap);
			if (r < 0) { va_end(ap); return (-1); }
			total += r;
		}
		else
		{
			/* Unknown specifier: print '%' then char */
			if (_putchar('%') < 0) { va_end(ap); return (-1); }
			if (_putchar(*p) < 0) { va_end(ap); return (-1); }
			total += 2;
		}
		p++;
	}
	va_end(ap);
	return (total);
}
