#include "main.h"

/**
 * _strncat - concatenates two strings, using at most n bytes from src
 * @dest: destination buffer
 * @src: source string
 * @n: maximum number of bytes to copy from src
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';

	return (dest);
}
