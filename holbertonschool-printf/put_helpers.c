#include "holberton.h"

/**
 * _putchar - write a single character to stdout
 * @c: character to write
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

/**
 * _write_buf - write len bytes from buf to stdout
 * @buf: buffer to write
 * @len: number of bytes
 *
 * Return: number of bytes written, or -1 on error
 */
int _write_buf(const char *buf, int len)
{
	int written = 0;
	int r;

	while (written < len)
	{
		r = write(1, buf + written, len - written);
		if (r <= 0)
			return (-1);
		written += r;
	}
	return (written);
}
