#include <stdlib.h>
#include "main.h"
/**
 * array_range - task 03
 * @min : value min
 * @max : value max
 * Description: function that creates an array of integers.
 * Return: always
 */
int *array_range(int min, int max)
{
	int *array;
	int i = 0, len = 0;

	if (min > max)
		return (NULL);
	len = ((max - min) + 1);

	array = malloc(len * sizeof(int));

	if (array == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		array[i] = min++;
	}
	return (array);
}
