#include "main.h"
/**
 * reverse_array - task 04
 * @a : Array
 * @n : Long of the array
 * Description:  function that reverses the content of an array of integers
 * Return: always
 */
void reverse_array(int *a, int n)
{
	int i = 0;
	int rev;

	while (i < n--)
	{
		rev = a[i];
		a[i++] = a[n];
		a[n] = rev;
	}
}
