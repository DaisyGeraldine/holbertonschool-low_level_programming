#include "main.h"
/**
 * print_last_digit - task 07
 * @n : variable to declarate
 * Description: function that prints the last digit of a number
 * Return: last_digit
 */
int print_last_digit(int n)
{
	int ud;

	ud = (n % 10);
	if (n < 0)
	{
		_putchar('0' + -ud);
		return (-ud);
	}
	else
	{
		_putchar('0' + ud);
		return (ud);
	}
}
