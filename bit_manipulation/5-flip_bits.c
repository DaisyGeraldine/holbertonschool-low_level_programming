#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * countSetBits - task 05
 * @n : number decimal.
 * Description: Function that count set bits.
 * Return: count.
 */
int countSetBits(int n)
{
	int count = 0;

	while (n > 0)
	{
		count++;
		n &= (n - 1);
	}
	return (count);
}
/**
 * flip_bits - task 05
 * @n : number first.
 * @m : number second.
 * Description: function that returns the number of bits you
 * would need to flip to get from one number to another.
 * Return: return count of flipped number.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
/* Return count of set bits in a XOR b*/
	return (countSetBits(n ^ m));
}
