#include "main.h"

/**
 * is_delim - helper to check word delimiters
 * @c: character to check
 *
 * Return: 1 if delimiter, 0 otherwise
 */
static int is_delim(char c)
{
	char *delims = " \t\n,;.!?\"(){}";

	while (*delims)
	{
		if (c == *delims)
			return (1);
		delims++;
	}
	return (0);
}

/**
 * cap_string - capitalizes all words of a string
 * @s: string to modify
 *
 * Return: pointer to s
 */
char *cap_string(char *s)
{
	int i = 0;

	if (s[0] >= 'a' && s[0] <= 'z')
		s[0] -= 'a' - 'A';

	for (i = 1; s[i] != '\0'; i++)
	{
		if (is_delim(s[i - 1]) && (s[i] >= 'a' && s[i] <= 'z'))
			s[i] -= 'a' - 'A';
	}

	return (s);
}
