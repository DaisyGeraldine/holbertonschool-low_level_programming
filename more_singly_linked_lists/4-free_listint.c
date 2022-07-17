#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 * free_listint - task 04
 * @head : pointer of struct list_t
 * Description: function that frees a listint_t list.
 * Return: always
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

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
