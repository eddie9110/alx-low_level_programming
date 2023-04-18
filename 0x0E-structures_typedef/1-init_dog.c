#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - initialises structure dog
 * @d: pointer parameter to struct dog
 * @name: name parameter = name of dog
 * @age: age parameter = age of dog in years
 * @owner: parameter = dog owner’s name
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = name;
	d->age = age;
	d->owner = owner;
}
