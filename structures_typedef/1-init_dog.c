#include "dog.h"
/**
 * init_dog - task 01
 * @d : struct dog
 * @name : char name
 * @age : float age
 * @owner : char owner
 * Description:  function that initialize a variable of type struct dog
 * Return: always
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return;

	d->name = name;
	d->age = age;
	d->owner = owner;

}
