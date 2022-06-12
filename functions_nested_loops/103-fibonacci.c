#include <stdio.h>
/**
 * main - task 15
 * Description: Prints the sum of the even-valued terms (Fibonacci)
 * Return: always
 */
int main(void)
{
	int cont;
	long int x = 0, y = 1, z = 0, sum = 0;

	for (cont = 1; cont <= 50; cont++)
	{
		z = x + y;
		if (sum <= 4000000)
			if (z % 2 == 0)
				sum += z;
		x = y;
		y = z;
	}
	printf("%ld\n", sum);
	return (0);
}
