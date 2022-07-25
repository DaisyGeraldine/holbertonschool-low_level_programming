#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * print_dlistint - task 00
 * @h : pointer of struct list_t
 * Description: function that prints all the elements of a dlistint_t list.
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	int nodos = 0;

	if (!h)
		return (0);

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		nodos++;
	}
	return (nodos);
}
