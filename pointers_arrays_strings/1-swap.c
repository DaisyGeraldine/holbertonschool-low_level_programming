#include "main.h"
/**
 * swap_int - task 01
 * @a : 1th variable
 * @b : 2th variable
 * Description: function that swaps the values of two integers
 * Return: always
 */
void swap_int(int *a, int *b)
{
	int aa, bb;

	aa = *a;
	bb = *b;
	*a = bb;
	*b = aa;
}
