#include <stdio.h>
#include "main.h"
/**
 * main - task 09
 * Description: function that prints a square
 * Return: always
 */
int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 == 0) /*multiples of both three and five*/
		{
			printf("FizzBuzz");
		}
		else if (i % 3 == 0) /*multiples of three*/
		{
			printf("Fizz");
		}
		else if (i % 5 == 0) /*multiples of five*/
		{
			printf("Buzz");
		}
		else
		{
			printf("%d", i);
		}
		if (i != 100)
			printf(" ");
	}
	printf("\n");
	return (0);
}
