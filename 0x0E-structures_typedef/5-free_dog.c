#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - ftn to release memory given to struct dog
 * @d: pointer parameter to struct dog
 */

void free_dog(dog_t *d)
{
	if (d)
	{
		free(d);
		free(d->owner);
		free(d->name);
	}
}
