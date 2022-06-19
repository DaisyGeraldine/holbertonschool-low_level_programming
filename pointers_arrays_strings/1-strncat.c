#include "main.h"
/**
 * _strncat - task 01
 * @dest : Cadena "Hello"
 * @src : Cadena "World\n"
 * @n : number of letters to concatenate
 * Description: function that concatenates two strings
 * Return: always
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0, k, f = 0;

	while (*(dest + i))
		i++;
	while (*(src + j))
		j++;

	if (n > j)
		n = j;

	for (k = i; k < (i + n); k++)
	{
		dest[k] = src[f];
		f++;
	}

/*	if (i != 0)*/
/*		dest[k] = '\n';*/

	k++;
	dest[k] = '\0';

	return (dest);
}
