#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 *  binary_to_uint - task 00
 * @b : pointer of array
 * Description: function that converts a binary number to an unsigned int.
 * Return: the converted number.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int val;

	if (b == NULL)
		return (0);

	for (val = 0; *b; b++)
	{
		if (*b == '1')
			val = (val << 1) | 1;
		else if (*b == '0')
			val = val << 1; /*val <<= 1;*/
		else
		return (0);
	}

	return (val);
}
