#include "main.h"

/* Forward declaration of helper function */
int _is_prime_helper(int n, int i);

/**
 * is_prime_number - checks if n is prime
 * @n: number to check
 *
 * Return: 1 if prime, 0 if not
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (_is_prime_helper(n, 2));
}

/**
 * _is_prime_helper - helper to check divisibility
 * @n: number to check
 * @i: current divisor
 *
 * Return: 1 if prime, 0 if divisible
 */
int _is_prime_helper(int n, int i)
{
	if (i * i > n)
		return (1);
	if (n % i == 0)
		return (0);
	return (_is_prime_helper(n, i + 1));
}
