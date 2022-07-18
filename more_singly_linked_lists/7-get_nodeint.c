#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 * get_nodeint_at_index - task 07
 * @head : pointer of struct list_t
 * Description: function that returns the nth node of a listint_t linked list.
 * Return: always
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
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
