#include "main.h"
/**
 * is_prime_number - task 06
 * @n : value integer
 * Description: function that returns 1 if the input integer is a prime number,
 * otherwise return 0
 * Return: always
 */
int is_prime_number(int n)
{
	return (is_divisible_number(n, 2));
}

/**
 * is_divisible_number - task 06
 * @num : number prime
 * @i : number of times divisible
 * Description: function that returns 1 if the input integer is a prime number,
 * otherwise return 0
 * Return: always
 */
int is_divisible_number(int num, int i)
{
	/*static int i = 2; no valida the checker the intranet*/

	if (num <= 2)
	{
		if (num == 2)
			return (1);
		else
			return (0);
	}
	if (num % i == 0)
		return (0);
	if (i * i > num)
		return (1);

	return (is_divisible_number(num, i + 1));
}
