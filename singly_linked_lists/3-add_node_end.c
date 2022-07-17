#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 * add_node_end - task 03
 * @head : double pointer of struct list_t
 * @str : string
 * Description: function that adds a new node at the end of a list_t list.
 * Return: the address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *temp, *ult;

	ult = malloc(sizeof(list_t));

	if (ult == NULL)
		return (NULL);

	ult->str = strdup(str);

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
