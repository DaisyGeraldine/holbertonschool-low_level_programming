#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * add_nodeint - task 01
 * @head : Double pointer struct listint_t
 * @n : number
 * Description: function that adds a new node at the
 * beginning of a listint_t list.
 * Return: Struct listint_t
 */
listint_t *add_nodeint(listint_t **head, const int n)
{

	listint_t *temp;

	temp = malloc(sizeof(listint_t));

	if (temp == NULL)
		return (NULL);

	temp->n = n;
	temp->next = *head;
	*head = temp;

	return (temp);
}
