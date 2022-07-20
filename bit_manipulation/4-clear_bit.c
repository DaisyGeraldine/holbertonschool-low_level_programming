#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * clear_bit - task 04
 * @n : number decimal.
 * @index : index.
 * Description: function that sets the value of a bit to 0 at a given index.
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = 1 << index, b = 0, r = 0;

	if (index >= 65)
		return (-1);

	r = ((*n & ~mask) | (b << index));

	*n = r;

	if (*n)
		return (1);
	else
		return (-1);
}
