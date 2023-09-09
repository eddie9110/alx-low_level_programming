#include "hash_tables.h"

/**
 * hash_djb2 - a function that uses the djb2 algorithm for hashing
 * @str: String to be hashed
 * Return: hash
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}
