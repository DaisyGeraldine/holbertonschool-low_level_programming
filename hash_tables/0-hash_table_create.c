#include <stdlib.h>
#include <string.h>
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

	ht_new = malloc(size * sizeof(hash_table_t));

	if (!ht_new)
		return (NULL);

	ht_new->size = size;
	ht_new->array = malloc(size * sizeof(hash_node_t));

	if (!ht_new->array)
	{
		free(ht_new);
		return (NULL);
	}

	while (i < size)
	{
		ht_new->array[i] = NULL;
		i++;
	}

	return (ht_new);
}
