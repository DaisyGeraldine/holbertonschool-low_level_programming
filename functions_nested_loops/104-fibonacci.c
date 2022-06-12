#include <stdio.h>
/**
 * main - task 14
 * Description: Prints the first 50 Fibonacci numbers
 * Return: always
 */
int main(void)
{
	int cont;
	unsigned int x = 0, y = 1, z = 0;

	for (cont = 1; cont <= 98; cont++)
	{
		z = x + y;
		printf("%u", z);
		if (cont != 98)
			printf(", ");
		x = y;
		y = z;
	}
	printf("\n");
	return (0);
}
