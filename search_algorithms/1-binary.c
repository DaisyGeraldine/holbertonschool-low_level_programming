#include <stdio.h>
#include "search_algos.h"
/**
 * binary_search - task 01
 * @array :  is a pointer to the first element of the array to search.
 * @size :  is the number of elements in array.
 * @value : is the value to search for.
 * Description: function that searches for a value in a sorted
 * array of integers using the Binary search algorithm.
 * Return: the index where value is located, otherwise -1.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t l = 0, i = 0, h = size - 1;
	int m = 0;

	if (!array || size < 2)
		return (-1);

	while (l < size)
	{
		printf("Searching in array: ");
		i = l;
		while (i < (h + 1))
		{
			if (i != l)
				printf(", ");
			printf("%d", array[i]);
			i++;
		}
		printf("\n");
		m = (l + h) / 2;
		if (array[m] == value)
			return (m);
		if (array[m] < value)
			l = m + 1;
		else
			h = m - 1;
	}
	return (-1);
}
