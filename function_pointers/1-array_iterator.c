#include <stdlib.h>
#include "function_pointers.h"
/**
 * array_iterator - task 01
 * @array : array
 * @size : size
 * @action : function
 * Description: function that executes a function given as a
 * parameter on each element of an array.
 * Return: always
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i = 0;

	if (array == NULL)
		return;
	if (action == NULL)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
