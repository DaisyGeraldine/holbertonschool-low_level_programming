#include <stdlib.h>
#include "main.h"
/**
 * str_concat - task 02
 * @s1 : string first
 * @s2 : string second
 * Description: function that concatenates two strings.
 * Return: always
 */
char *str_concat(char *s1, char *s2)
{
	char *str;
	int i = 0, j = 0, len1 = 0, len2 = 0;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	while (s1[len1] != '\0')
	{
		len1++;
	}
	while (s2[len2] != '\0')
	{
		len2++;
	}
	len2++;
	str = malloc(len1 + len2 * sizeof(char));

	if (str == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len1; i++)
	{
		str[i] = s1[i];
	}
	for (i = len1; i < (len1 + len2); i++)
	{
		str[i] = s2[j];
		j++;
	}
	return (str);
}
