#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * listint_len - task 01
 * @h : pointer of struct list_t
 * Description: function that returns the number of elements in a
 * linked listint_t list.
 * Return: number of items
 */
size_t listint_len(const listint_t *h)
{
	int c = 0;

	if (h == NULL)
		return (0);

	while (h)
	{
		h = h->next;
		c++;
	}

	return (c);
}
