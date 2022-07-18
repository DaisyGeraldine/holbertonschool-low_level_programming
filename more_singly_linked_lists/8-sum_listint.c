#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 * sum_listint - task 08
 * @head : pointer of struct list_t
 * Description: function that returns the sum of all the data (n) of a
 * listint_t linked list.
 * Return: sum
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	if (head == NULL)
		return (0);

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
