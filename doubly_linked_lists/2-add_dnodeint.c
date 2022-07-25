#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * add_dnodeint - task 01
 * @head : Double pointer struct listint_t
 * @n : number
 * Description: function that adds a new node at the
 * beginning of a dlistint_t list.
 * Return: Struct listint_t
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node = NULL, *temp = NULL;

	new_node = malloc(sizeof(dlistint_t));

	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = n;
	/* head hace referencia a la direccion*/
	/* *head hace referencia a la struc*/
	if (!head || !(*head))
	{
		*head = new_node;
		return (new_node);
	}
	else
	{
		temp = *head;
		temp->prev = new_node;
		*head = new_node;
		new_node->next = temp;
		return (new_node);
	}
	return (NULL);
}
