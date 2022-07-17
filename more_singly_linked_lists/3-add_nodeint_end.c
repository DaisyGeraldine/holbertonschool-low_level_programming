#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * add_nodeint_end - task 03
 * @head : Double pointer struct listint_t
 * @n : number
 * Description: function that adds a new node at the end of a listint_t list.
 * Return: Struct listint_t
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *temp, *ult;

	ult = malloc(sizeof(listint_t));

	if (ult == NULL)
		return (NULL);

	ult->n = n;

	if (*head == NULL)
	{
		ult->next = *head;
		*head = ult;
	}
	else
	{
		ult->next = NULL;
		temp = *head;

		while (temp->next)
			temp = temp->next;
		temp->next = ult;
	}

	return (ult);
}
