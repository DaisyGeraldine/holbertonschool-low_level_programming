#include "main.h"
/**
 * print_diagonal - task 06
 * @n : numbers to validate
 * Description: function that draws a diagonal line on the terminal
 * Return: always
 */
void print_diagonal(int n)
{
	int d, e;

	for (d = 0; d < n; d++)
	{
		for (e = 0; e < d; e++)
		{
			_putchar(32);
		}
		_putchar(92);
		_putchar(10);
	}
	if (n <= 0)
		_putchar(10);
}
