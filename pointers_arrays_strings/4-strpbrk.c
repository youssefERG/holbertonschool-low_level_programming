#include "main.h"

/**
 * _strpbrk - searches a string for any set of bytes
 * @s: string to search
 * @accept: string containing bytes to match
 *
 * Return: pointer to first occurrence in s or NULL
 */
char *_strpbrk(char *s, char *accept)
{
	unsigned int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				return (s + i);
		}
	}

	return (0);
}
