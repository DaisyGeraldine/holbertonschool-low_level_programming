#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - Entry point
 *
 * Description: 'Print last digit of a number random'
 * Betty style doc for function main goes there
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n, d;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	d = n % 10;
	if (d > 5 && d <= 9)
	{
		printf("Last digit of %d is %d and is greater than 5\n", n, d);
	}
	if (d < 6)
	{
		if (d == 0)
		{
			printf("Last digit of %d is %d and is 0\n", n, d);
		}
		else
		{
			printf("Last digit of %d is %d and is less than 6 and not 0\n", n, d);
		}
	}
	return (0);
}
