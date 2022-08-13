#include <stdlib.h>
#include "main.h"
/**
 * free_grid - task 04
 * @grid :  array bidimensional
 * @height: Rows array
 * Description:  function that frees a 2 dimensional grid previously created
 * Return: nothing
 */
void free_grid(int **grid, int height)
{
	int i = 0;
	(void)height;

	if (grid == NULL)
		return;

	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
