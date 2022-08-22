#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash_tables.h"
/**
 * hash_table_print - task 05
 * @ht  : is the hash table
 * Description: function that prints a hash table.
 * Return: nothing.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *p = NULL;
	char n;

	printf("{");
	for (i = 0; ht && i < ht->size; i++)
	{
		p = ht->array[i];
		n = 0;
		while (p)
		{
			if (n)
				printf(", ");
			printf("'%s': '%s'", p->key, p->value);
			p = p-> next;
			n = 1;
		}
	}
	printf("}\n");
}
