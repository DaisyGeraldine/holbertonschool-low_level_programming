#include "main.h"
#include <math.h>
#include <float.h>
/**
 * _recursion - task 05
 * @num : value
 * @prev : value
 * Description: function that returns the natural square root of a number
 * Return: always
 */
float _recursion(float num, float prev)
{
	float next = (prev + num / prev) / 2;

	if (fabs(next - prev) < FLT_EPSILON * next)
		return (next);
	return (_recursion(num, next));
}
/**
 * _sqrt_recursion - task 05
 * @n : value integer
 * Description: function that returns the natural square root of a number
 * Return: always
 */
int _sqrt_recursion(int n)
{
	int dev;

	if (n < 0)
		return (-1);

	dev =  _recursion(n, 1);

	if ((dev * dev) == n)
		return (dev);
	else
		return (-1);
}
