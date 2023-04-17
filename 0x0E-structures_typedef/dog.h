#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a structure ontaining a dog's info
 * @name: first parameter = name of the dog
 * @age: Second parameter is age in yrs of dog
 * @owner: third parameter name of the dog owner
 * dog_t - an alias/typedef for struct dog
 */

typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

#endif
