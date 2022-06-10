#include "main.h"
/**
 * print_sign - task 05
 * @n : Caracter to validate
 * Description: function that prints the sign of a number
 * Return: Always + , 0 , -
 */
int print_sign(int n)
{
	char r;

	if (n > 0)
	{
		r = _putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		r = _putchar('0');
		return (0);
	}
	else
	{
		r = _putchar('-');
		return (-1);
	}
	return (r);
}
