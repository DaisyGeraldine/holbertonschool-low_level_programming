#include "main.h"
/**
 * leet - task 07
 * @s : Array
 * Description: function that encodes a string into 1337
 * Return: always
 */
char *leet(char *s)
{
	int i, j;
	char len[10] = "aAeEoOtTlL", str[10] = "4433007711";

	for (i = 0; s[i] != '\0'; i++)
	{
		j = 0;
		for (; j < 10; j++)
		{
			if (s[i] == len[j])
				s[i] = str[j];
		}
	}
	return (s);
}
