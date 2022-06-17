#include "main.h"
/**
 * _strcpy - task 09
 * @dest : variable char
 * @src : variable char
 * Description: function that copies the string pointed to by src
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; i <= _strlen(src); i++)
		dest[i] = src[i];

	return (dest);
}
