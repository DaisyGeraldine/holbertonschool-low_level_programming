#include "main.h"
/**
 * _abs - task 06
 * @n : variable to declarate
 * Description: function that computes the absolute value of an integer
 * Return: Absolute value
 */
int _abs(int n)
{
	if (n < 0)
	{
		n = n * -1;
	}
	else
	{
		n = n;
	}
	return (n);
}
