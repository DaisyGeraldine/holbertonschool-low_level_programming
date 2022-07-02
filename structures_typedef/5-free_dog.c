#include <stdlib.h>
#include "dog.h"
/**
 * free_dog - task 05
 * @d : pointer dog
 * Description: function that frees dogs
 * Return: always
 */
void free_dog(dog_t *d)
{
	free(d->name);
	free(d->owner);
	free(d);
}
