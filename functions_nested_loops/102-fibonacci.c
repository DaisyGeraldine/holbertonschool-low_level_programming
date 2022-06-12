#include <stdio.h>
/**
 * main - task 14
 * Description: Prints the first 50 Fibonacci numbers
 * Return: always
 */
int main(void)
{
	int cont;
	long int x = 0, y = 1, z = 0;

	for (cont = 1; cont <= 50; cont++)
	{
		z = x + y;
		printf("%ld\n", z);
		x = y;
		y = z;
	}
	return (0);
}
