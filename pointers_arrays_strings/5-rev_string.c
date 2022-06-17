#include "main.h"
/**
 * rev_string - task 05
 * @s : Variable char to validate
 * Description: function that reverses a string
 * Return: always
 */
void rev_string(char *s)
{
	int i = 0, j = 0;
	char inv;

	while (s[i] != '\0')
		i++;

	while (j < i--)
	{
		inv = s[j];
		s[j++] = s[i];
		s[i] = inv;
	}
}
