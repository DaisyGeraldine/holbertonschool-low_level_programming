#include "main.h"
#include <string.h>
#include <stdio.h>
/**
 * _strspn - task 03
 * @s : string
 * @accept : string to validate
 * Description: function that gets the length of a prefix substring.
 * Return: the number of bytes in the initial segment of s.
 */
unsigned int _strspn(char *s, char *accept)
{
	int count = 0, flag;
	char *start = accept;

	while (*s)
	{
		flag = 0;
		while (*accept)
		{
			if (*accept == *s)
			{
				count++;
				flag = 1;
				break;
			}
			accept++;
		}
		s++;
		accept = start;
		if (flag == 0)
			break;
	}
	return (count);
}
