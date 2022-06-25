#include <stdlib.h>
#include "main.h"
/**
 * create_array - task 00
 * @size : size of the array
 * @c : character specific
 * Description: function that creates an array of chars, and initializes
 * it with a specific char.
 * Return: always
 */
char *create_array(unsigned int size, char c)
{
	char *str;
	unsigned int i = 0;

	if (size == 0)
	{
		str = NULL;
	}
	else
	{
		str = malloc(size);
		i = 0;

		while (i < size)
		{
			str[i] = c;
			i++;
		}
	}
	return (str);
}
