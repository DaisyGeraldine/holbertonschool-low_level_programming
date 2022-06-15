#include "main.h"
/**
 * print_triangle - task 10
 * @size : size of triangle
 * Description: function that prints a triangle
 * Return: always
 */
void print_triangle(int size)
{
	int i, j;

	for (i = size; i >= 1; i--)
	{
		for (j = 1; j <= size; j++)
		{
			if (j >= i)
				_putchar(35);
			else
				_putchar(32);
		}
		_putchar(10);
	}
	if (size <= 0)
		_putchar(10);
}
