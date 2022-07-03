#include <stdlib.h>
#include "function_pointers.h"
/**
 * int_index - task 02
 * @array : array
 * @size : size
 * @cmp : function
 * Description: function that searches for an integer.
 * Return: always
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0, devint = 0, ret = -1;

	if (size <= 0)
		return (ret);
	if (array == NULL)
		return (ret);
	if (cmp == NULL)
		return (ret);

	for (i = 0; i < size; i++)
	{
		devint = cmp(array[i]);

			if (devint == 1)
				return (i);
	}

	return (ret);
}
