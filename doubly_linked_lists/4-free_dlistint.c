#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 * free_dlistint - task 04
 * @head : pointer of struct list_t
 * Description: function that frees a dlistint_t list.
 * Return: always
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	if (!head)
		return;

	while (head)
	{
		temp = head;
		head = head->next;
		/*free(temp->n);*/
		free(temp);
	}
}
