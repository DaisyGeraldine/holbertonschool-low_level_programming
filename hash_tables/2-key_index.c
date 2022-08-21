#include <stdlib.h>
#include "hash_tables.h"
/**
 * key_index - task 02
 * @key : is the key
 * @size :  is the size of the array of the hash table.
 * Description: function that gives you the index of a key.
 * Return:  the index at which the key/value pair should
 * be stored in the array of the hash table.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned int long index = 0;

	index = hash_djb2((unsigned char *)s);

	return (index % size);
}
