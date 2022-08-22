#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash_tables.h"
/**
 * hash_table_delete - task 06
 * @ht  : is the hash table
 * Description: function that deletes a hash table.
 * Return: nothing.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned int long i = 0;
	hash_node_t *temp = NULL;

	while (i < ht->size)
	{
		temp = ht->array[i];

		while (temp)
		{
			temp = ht->array[i];
			ht->array[i] = ht->array[i]->next;
			free(temp->value);
			free(temp->key);
			free(temp);
			temp = NULL;
		}
		i++;
		/*if (!temp)
		{
			free(temp);
			temp = NULL;
			}*/
	}
	free(ht->array);
	free(ht);
}
