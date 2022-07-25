#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 * get_dnodeint_at_index - task 05
 * @head : pointer of struct list_t
 * @index : index to choose
 * Description: function that returns the nth node of a dlistint_t linked list.
 * Return: always
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int c = 0;

	if (head == NULL)
		return (NULL);

	while (head)
	{
		if (c == index)
			return (head);
		head = head->next;
		c++;
	}

	return (NULL);
}
