#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * list_len - task 01
 * @h : pointer of struct list_t
 * Description: function that returns the number of elements in a
 * linked list_t list.
 * Return: number of items
 */
size_t list_len(const list_t *h)
{
	size_t c = 0;

	while (h)
	{
		h = h->next;
		c++;
	}

	return (c);
}
