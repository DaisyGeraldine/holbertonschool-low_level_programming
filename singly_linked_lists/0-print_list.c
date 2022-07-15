#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * print_list - task 00
 * @h : pointer of struct list_t
 * Description: function that prints all the elements of a list_t list.
 * Return: number of items
 */
size_t print_list(const list_t *h)
{
	size_t c = 0;
	int i = 0;

	while (h)
	{
		if (h->str == NULL)
			i = 0;
		else
			while (h->str[i])
				i++;
		printf("[%u] ", i);
		if (h->str == NULL)
			printf("(nil)\n");
		else
			printf("%s\n", h->str);
		h = h->next;
		c++;
	}
	return (c);
}
