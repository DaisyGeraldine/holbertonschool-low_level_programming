#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 * add_node - task 02
 * @head : double pointer of struct list_t
 * @str : string
 * Description: function that adds a new node at the
 * beginning of a list_t list.
 * Return: the address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *temp;

	temp = malloc(sizeof(list_t));

	if (temp == NULL)
		return (NULL);

	temp->str = strdup(str);
	temp->next = *head;
	*head = temp;

	return (temp);
}
