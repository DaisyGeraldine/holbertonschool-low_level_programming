#include <stdlib.h>
#include "main.h"
/**
 * string_nconcat - task 01
 * @s1 : string first
 * @s2 : string second
 * @n : longitud the caracteres of s2
 * Description: function that concatenates two strings
 * Return: always
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;
	unsigned int len1 = 0, len2 = 0, lenf = 0, c1 = 0, c2 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	len1 = _len(s1);
	len2 = _len(s2);

	if (n >= len2)
		lenf = len2 + len1;
	else
		lenf = n + len1;

	str = malloc((lenf + 1) * sizeof(char));

	if (str == NULL)
		return (NULL);
	for (c1 = 0; c1 < lenf; c1++)
	{
		if (c1 < len1)
			str[c1] = s1[c1];
		else
			str[c1] = s2[c2++];
	}
	str[c1] = '\0';
	return (str);
}
/**
 * _len - task 01
 * @s : Variable char to validate
 * Description: function that returns the length of a string
 * Return: always
 */
int _len(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}
