#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 * free_listint2 - task 05
 * @head : pointer of struct list_t
 * Description: function that frees a listint_t list.
 * Return: always
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
		return;

	if (!(*head))
		return;

	while (*head)
	{
		temp = *head;
		(*head) = (*head)->next;
		free(temp);
	}
}
