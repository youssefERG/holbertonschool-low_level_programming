#include "main.h"

/**
 * print_triangle - prints a triangle using #
 * @size: size of the triangle
 *
 * Return: void
 */
void print_triangle(int size)
{
	int i;
	int col;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (i = size; i > 0; i--)
		{
			for (col = 1; col <= size; col++)
			{
				if (col < i)
					_putchar(' ');
				else
					_putchar('#');
			}
			_putchar('\n');
		}
	}
}
