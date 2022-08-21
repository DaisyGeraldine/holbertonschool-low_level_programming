#include <stdlib.h>
#include "hash_tables.h"
/**
 * hash_table_create - task 00
 * @size : is the size of the array.
 * Description: function that creates a hash table.
 * Return: a pointer to the newly created hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht_new;
	unsigned long int i = 0;

	ht_new = malloc(sizeof(hash_table_t));

	if (!ht_new)
		return (NULL);

	ht_new->array = malloc(size * sizeof(hash_node_t *));
	ht_new->size = size;

	if (!ht_new->array)
	{
		free(ht_new);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht_new->array[i] = NULL;

	return (ht_new);
}
