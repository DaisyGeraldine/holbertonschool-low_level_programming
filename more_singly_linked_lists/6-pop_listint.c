#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 * pop_listint - task 06
 * @head : pointer of struct list_t
 * Description: function that deletes the head node of a listint_t linked list,
 * and returns the head node’s data (n).
 * Return: always
 */
int pop_listint(listint_t **head)
{
	int retval = -1;
	listint_t *next_node = NULL;

	if (*head == NULL)
		return (-1);

	next_node = (*head)->next;
	retval = (*head)->n;
	free(*head);
	*head = next_node;

	return (retval);
}
