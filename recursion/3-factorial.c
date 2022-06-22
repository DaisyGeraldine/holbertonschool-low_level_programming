#include "main.h"
/**
 * factorial - task 03
 * @n : value integer
 * Description: function that returns the factorial of a given number
 * Return: always
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);
	else
		return (n * factorial(n - 1));
}
