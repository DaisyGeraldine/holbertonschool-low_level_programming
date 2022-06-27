#include <stdlib.h>
#include "main.h"
/**
 * _strdup - task 01
 * @str : size of the array
 * Description: Function that returns a pointer to a newly allocated
 * space in memory.
 * Return: always
 */
char *_strdup(char *str)
{
	int i = 0, len = 0;
	char *cad;

	if (str == NULL)
	{
		cad = NULL;
	}
	else
	{
		while (str[len] != '\0')
		{
			len++;
		}
		len++;
		cad = malloc(len * sizeof(char));
	}
	for (i = 0; i < len; i++)
	{
		cad[i] = str[i];
	}
	return (cad);
}
