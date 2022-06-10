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

	if (n < 0)
	{
		n = -n;
	}
	ud = (n % 10);
	_putchar('0' + (n % 10));
	return (ud);
}
