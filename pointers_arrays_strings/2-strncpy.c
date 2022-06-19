#include "main.h"
/**
 * _strncpy - task 02
 * @dest : Long string
* @src :String
 * @n : number of letters to copy
 * Description: function that copies a string
 * Return: always
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0, j = 0, k, f = 0;

	while (*(dest + i))
		i++;

	while (*(src + j))
		j++;

	for (k = 0; k < n; k++)
	{
		dest[k] = src[f];
		f++;
	}

	return (dest);
}
