#include <stdio.h>
#include "search_algos.h"
/**
 * linear_search - task 00
 * @array :  is a pointer to the first element of the array to search.
 * @size :  is the number of elements in array.
 * @value : is the value to search for.
 * Description: function that searches for a value in an
 * array of integers using the Linear search algorithm.
 * Return: the first index where value is located, otherwise -1.
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i = 0;

	if (!array)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
