#include "main.h"
#include <string.h>
#include <stdio.h>
/**
 * print_chessboard - task 06
 * @a : string
 * Description: function that prints the chessboard.
 * Return: nothing
 */
void print_chessboard(char (*a)[8])
{
	int i = 0, j = 0;

	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			_putchar(a[i][j]);
			j++;
		}
		_putchar(10);
		i++;
	}
}
