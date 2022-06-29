#include <stdlib.h>
#include "main.h"
/**
 * alloc_grid - task 03
 * @width : Column array
 * @height: Rows array
 * Description:  function that returns a pointer to a
 * 2 dimensional array of integers.
 * Return: always
 */
int **alloc_grid(int width, int height)
{
	int c = width, r = height, num = 0, i;

	/*ptr = (int**)malloc(sizeof(int) * 48);*/
	int **ptr = (int **)malloc(r * sizeof(int *));

	if (c <= 0 || r <= 0)
		return (NULL);

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < r; i++)
	{
		ptr[i] = (int *)malloc(c * sizeof(int));

		if (ptr[i] == NULL)
		{
			for (--i; i >= 0; i--)
				free(ptr[i]);
			free(ptr);
			return (NULL);
		}
	}

	for (r = 0; r < width; r++)
		for (c = 0; c < height; c++)
			ptr[c][r] = num;
	return (ptr);
}
