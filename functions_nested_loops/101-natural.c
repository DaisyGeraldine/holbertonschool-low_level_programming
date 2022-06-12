#include <stdio.h>
/**
 * main - task 12
 * Description: Computes the sum of the multiples of 3 or 5
 * Return: always
 */
int main(void)
{
	int n = 0, sum;

	for (n = 0; n < 1024; n++)
	{
		if ((n % 3) == 0 || (n % 5) == 0)
		{
			sum += n;
		}
	}
	printf("%d\n", sum);
	return (0);
}
