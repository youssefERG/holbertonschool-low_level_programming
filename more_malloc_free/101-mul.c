#include "main.h"
#include <ctype.h>

/**
 * _isdigit - checks if a string is a digit
 * @s: string
 *
 * Return: 1 if all digits, 0 otherwise
 */
int _isdigit(char *s)
{
    int i = 0;

    while (s[i])
    {
        if (!isdigit(s[i]))
            return (0);
        i++;
    }
    return (1);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
    int i, j, len1, len2, *result, start = 0, carry, n1, n2;
    char *s1, *s2;

    if (argc != 3 || !_isdigit(argv[1]) || !_isdigit(argv[2]))
    {
        printf("Error\n");
        exit(98);
    }

    s1 = argv[1];
    s2 = argv[2];

    for (len1 = 0; s1[len1]; len1++)
        ;
    for (len2 = 0; s2[len2]; len2++)
        ;

    result = calloc(len1 + len2, sizeof(int));
    if (result == NULL)
        exit(98);

    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        n1 = s1[i] - '0';
        for (j = len2 - 1; j >= 0; j--)
        {
            n2 = s2[j] - '0';
            carry += result[i + j + 1] + (n1 * n2);
            result[i + j + 1] = carry % 10;
            carry /= 10;
        }
        if (carry)
            result[i + j + 1] += carry;
    }

    while (start < len1 + len2 && result[start] == 0)
        start++;

    if (start == len1 + len2)
        _putchar('0');
    else
        for (i = start; i < len1 + len2; i++)
            _putchar(result[i] + '0');

    _putchar('\n');
    free(result);
    return (0);
}
