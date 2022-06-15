#include "main.h"
/**
 * _strlen - task 02
 * @s : Variable char to validate
 * Description: function that returns the length of a string
 * Return: always
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
