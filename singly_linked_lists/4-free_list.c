#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 * free_list - task 04
 * @head : pointer of struct list_t
 * Description: function that frees a list_t list.
 * Return: always
 */
void free_list(list_t *head)
{
	list_t *temp;

	if (!head)
		return;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
