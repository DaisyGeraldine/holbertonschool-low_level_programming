#include <stdlib.h>
#include "main.h"
/**
 * _calloc - task 02
 * @nmemb : number elements
 * @size : size bytes for type elements
 * Description: function that allocates memory for an array, using malloc
 * Return: always
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i = 0;
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
		ptr[i] = 0;

	return (ptr);
}
