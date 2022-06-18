#include "main.h"
/**
 * _strcat - task 01
 * @dest : Cadena "Hello"
 * @src : Cadena "World\n"
 * Description: function that concatenates two strings
 * Return: always
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0, k, f = 0;

	while (*(dest + i))
	{
		i++;
	}

	while (*(src + j))
	{
		j++;
	}

	j--;

	for (k = i; k < (i + j); k++)
	{
		dest[k] = src[f];
		f++;
	}
	dest[k] = '\n';
	k++;
	dest[k] = '\0';
	return (dest);
}
