#include "main.h"
/**
 * print_line - task 06
 * @n : numbers to validate
 * Description: function that draws a straight line in the terminal
 * Return: always
 */
void print_line(int n)
{
	char c;

	for (c = 1; c <= n; c++)
	{
		_putchar(95);
	}
	_putchar(10);
}
