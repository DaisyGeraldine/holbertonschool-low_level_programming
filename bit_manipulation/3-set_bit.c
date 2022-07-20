#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * set_bit - task 03
 * @n : number decimal.
 * @index : index.
 * Description: function that sets the value of a bit to 1 at a given index.
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = 1 << index, b = 1, r = 0;

	r = ((*n & ~mask) | (b << index));

	*n = r;

	if (*n)
		return (1);
	else
		return (-1);
}
