#include "main.h"
/**
 * print_square - task 08
 * @size : size of square
 * Description: function that prints a square
 * Return: always
 */
void print_square(int size)
{
	int i, j;

	for (i = 1; i <= size; i++)
	{
		for (j = 1; j <= size; j++)
		{
			_putchar(35);
		}
		_putchar(10);
	}
	if (size == 0)
	_putchar(10);
}
