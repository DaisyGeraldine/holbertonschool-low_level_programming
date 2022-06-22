/**
 * is_prime_number - task 06
 * @n : value integer
 * Description: function that returns 1 if the input integer is a prime number,
 * otherwise return 0
 * Return: always
 */
int is_prime_number(int n)
{
	static int i = 2;

	if (n <= 2)
	{
		if (n == 2)
			return (1);
		else
			return (0);
	}
	if (n % i == 0)
		return (0);
	if (i * i > n)
		return (1);
	i++;
	return (is_prime_number(n));
}
