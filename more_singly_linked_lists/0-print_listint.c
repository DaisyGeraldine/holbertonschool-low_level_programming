#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * print_listint - task 00
 * @h : pointer of struct list_t
 * Description: function that prints all the elements of a listint_t list.
 * Return: number of items
 */
size_t print_listint(const listint_t *h)
{
	int c = 0;

	if (h == NULL)
		return (0);

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		c++;
	}
	return (c);
}
