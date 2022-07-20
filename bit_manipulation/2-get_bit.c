#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * get_bit - task 02
 * @n : number decimal.
 * @index : index.
 * Description: function that returns the value of a bit at a given index.
 * Return: the value of the bit at index.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bitStatus = 0;

	if (!n)
		return (-1);

	bitStatus = (n >> index) & 1;

	return (bitStatus);
}
