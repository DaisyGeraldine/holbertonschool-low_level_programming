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
	int decimal_num = 0, rem = 0, base = 1, num = 0;
	int i = 0;

	if (b == NULL)
		return (0);

	while (b[i] != '\0')
	{
		if (b[i] == '0' || b[i] == '1')
			i++;

		else
			return (0);
	}

	num = atoi(b);

	while (num > 0)
	{
		rem = num % 10;
		decimal_num = decimal_num + rem * base;
		num = num / 10;
		base = base * 2;
	}

	return (decimal_num);
}
