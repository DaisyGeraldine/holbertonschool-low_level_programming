#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash_tables.h"
/**
 * hash_table_set - task 03
 * @ht  : is the hash table you want to add or update the key/value.
 * @key : is the key.
 * @value : is the value associated with the key.
 * Description: function that adds an element to the hash table.
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *hn_new = NULL, *hn_add = NULL;
	unsigned int long index = 0;
	char *dup_value = NULL;

	if (!ht || !key || strcmp(key, "") == 0 || !value)
		return (0);

	index = key_index((unsigned char *)key, ht->size);


	hn_new = ht->array[index];

	while (hn_new)
	{
		if (strcmp(hn_new->key, key) == 0)
		{
			free(hn_new->value);
			dup_value = strdup(value);
			if (dup_value == NULL)
			{
				return (0);
			}
			hn_new->value = dup_value;
		}
		hn_new = hn_new->next;
	}
	hn_add = malloc(sizeof(hash_node_t));
	if (!hn_add)
		return (0);
	hn_add->key = strdup(key);
	hn_add->value = strdup(value);
	hn_add->next = ht->array[index];
	ht->array[index] = hn_add;

	return (1);

}
