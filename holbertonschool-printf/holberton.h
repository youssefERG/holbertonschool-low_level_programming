#ifndef HOLBERTON_H
#define HOLBERTON_H

/* Minimal headers required for the Holberton _printf project */
#include <stdarg.h> /* va_list, va_start, va_arg, va_end */
#include <unistd.h> /* write() */
#include <limits.h> /* INT_MIN, INT_MAX */

int _printf(const char *format, ...);

int _putchar(char c);
int _write_buf(const char *buf, int len);

int print_char(va_list ap);
int print_string(va_list ap);
int print_percent(void);
int print_int(va_list ap);

#endif /* HOLBERTON_H */
