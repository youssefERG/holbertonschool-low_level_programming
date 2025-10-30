#include "main.h"

/* Forward declaration of helper function */
int _sqrt_helper(int n, int i);

/**
 * _sqrt_recursion - returns the natural square root of n
 * @n: number to calculate
 *
 * Return: natural square root, or -1 if none exists
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (_sqrt_helper(n, 0));
}

/**
 * _sqrt_helper - helper function to find square root
 * @n: number to calculate
 * @i: current guess to check
 *
 * Return: square root, or -1 if none exists
 */
int _sqrt_helper(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (_sqrt_helper(n, i + 1));
}
