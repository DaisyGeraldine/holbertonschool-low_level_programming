#include <stdio.h>
#include "main.h"
/**
 * print_array - task 08
 * @a : array
 * @n : integer variable
 * Description:  function that prints half of a string, followed by a new line
 * Return: always
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if (i < (n - 1))
			printf(", ");
	}
	printf("\n");
}
