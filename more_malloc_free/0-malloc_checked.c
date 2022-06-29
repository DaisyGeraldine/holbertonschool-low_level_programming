#include <stdlib.h>
#include "main.h"
/**
 * malloc_checked - task 00
 * @b : longitud
 * Description: function that allocates memory using malloc
 * Return: always
 */
void *malloc_checked(unsigned int b)
{
	void *p;

	p = malloc(b);

	if (p == NULL)
		exit(98);
	return (p);
}
