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
	hash_table_t *ht;

	ht = malloc(size * sizeof(hash_table_t));

	return (ht);
}
