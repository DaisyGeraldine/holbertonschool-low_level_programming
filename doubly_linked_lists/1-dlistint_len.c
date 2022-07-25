#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * dlistint_len - task 01
 * @h : pointer of struct list_t
 * Description: unction that returns the number of elements in a
 * linked dlistint_t list.
 * Return: number of items
 */
size_t dlistint_len(const dlistint_t *h)
{
	int nodos = 0;

	if (!h)
		return (0);

	while (h)
	{
		h = h->next;
		nodos++;
	}

	return (nodos);
}
