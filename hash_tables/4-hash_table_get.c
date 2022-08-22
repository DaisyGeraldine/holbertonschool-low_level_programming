#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash_tables.h"
/**
 * hash_table_get - task 04
 * @ht  : is the hash table you want to look into.
 * @key : is the key you are looking for.
 * Description: function that retrieves a value associated with a key.
 * Return: the value associated, or NULL if key couldn’t be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned int long index = 0;
	char *ret = NULL;
	hash_node_t *hn_temp = NULL;

	if (!ht)
	{
		return (NULL);
	}

	index = key_index((unsigned char *)key, ht->size);
	hn_temp = ht->array[index];

	while (hn_temp)
	{
		if (strcmp(hn_temp->key, key) == 0)
		{
			ret = hn_temp->value;
			return (ret);
		}
		hn_temp = hn_temp->next;
	}
	return ("(null)");
}
