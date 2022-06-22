#include "main.h"
/**
 * _pow_recursion - task 05
 * @x : value integer
 * @y : value integer power
 * Description: function that returns the value of x raised to the power of y
 * Return: always
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}
	else if (y == 0)
	{
		return (1);
	}
	else
	{
		return (x * _pow_recursion(x, y - 1));
	}
}
