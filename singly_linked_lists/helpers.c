#include "lists.h"

/**
 * _strlen - returns the length of a string
 * @s: input string
 *
 * Return: number of characters in s (not counting null byte)
 */
unsigned int _strlen(const char *s)
{
	unsigned int i = 0;

	if (s == NULL)
		return (0);

	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * _strdup - duplicate a string using malloc
 * @s: source string
 *
 * Return: pointer to newly allocated string copy or NULL on failure
 */
char *_strdup(const char *s)
{
	unsigned int len, i;
	char *copy;

	if (s == NULL)
		return (NULL);

	len = _strlen(s);
	copy = malloc(len + 1);
	if (copy == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		copy[i] = s[i];
	copy[len] = '\0';

	return (copy);
}
