#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * argstostr - task 05
 * @ac : number argument
 * @av: arguments
 * Description: function that concatenates all the arguments of your program.
 * Return: a pointer to a new string, or NULL if it fails.
 */
char *argstostr(int ac, char **av)
{
	int i = 0, j = 0, len = 0;
	char *str = NULL;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			len++;
		len++;
	}

	str = malloc(len * sizeof(char));

	i =0;
	while (i < ac)
	{
		strcat(str, av[i]);
		strcat(str, "\n");
		i++;
	}
	return (str);
}
