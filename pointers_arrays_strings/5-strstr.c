#include "main.h"
#include <string.h>
#include <stdio.h>
/**
 * _strstr - task 05
 * @haystack : string
 * @needle : substring
 * Description: function that locates a substring
 * Return: a pointer to the beginning of the located substring.
 */
char *_strstr(char *haystack, char *needle)
{
	int i = 0, j;
	char *temp;

	if (haystack == NULL || needle == NULL)
		return (NULL);

	if (*needle == '\0')
		return (haystack);

	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			temp = haystack + i;
			j = 0;
			while (needle[j] == *temp && needle[j] != '\0')
			{
				j++;
				temp++;
			}
			if (needle[j] == '\0')
				return (haystack + i);
		}
		i++;
	}
	return (NULL);
}
