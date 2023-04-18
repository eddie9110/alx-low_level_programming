#include "dog.h"
#include <stdlib.h>

/**
 * _strlen - ftn to acquire lenth of string
 * @s: Pointer parameter to string of interest
 * Return: ka
 */
int _strlen(char *s)
{
	int ka = 0;

	while (s[ka] != '\0')
	{
		ka++;
	}

	return (ka);
}

/**
 * _strcpy - ftion that copies a string's content
 * @dest: pointer paraneter to destination of copied string
 * @src: pointer parameter to the source of the string
 * Return: destination dest
 */


char *_strcpy(char *dest, char *src)
{
	int lgt = 0;
	int ka;

	while (src[lgt] != '\0')
	{
		lgt++;
	}

	for (ka = 0; ka < lgt; ka++)
	{
		dest[ka] = src[ka];
	}
	dest[ka] = '\0';

	return (dest);
}

/**
 * new_dog - ftn is a pointer to info abt dog
 * @name: name of dog parameter
 * @age: parameter reps age of a dog in yrs
 * @owner: parameter reps name of owner of the dog
 * Return: (dog)
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	int lgta, lgtz;
	dog_t *dog;


	lgtz = _strlen(owner);
	lgta = _strlen(name);


	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);


	dog->name = malloc(sizeof(char) * (lgta + 1));

	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}

	dog->owner = malloc(sizeof(char) * (lgtz + 1));

	if (dog->owner == NULL)
	{
		free(dog);
		free(dog->name);
		return (NULL);
	}

	_strcpy(dog->name, name);
	_strcpy(dog->owner, owner);

	dog->age = age;


	return (dog);
}

