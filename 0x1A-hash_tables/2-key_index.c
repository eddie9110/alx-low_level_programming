#include "hash_tables.h"

/**
 * key_index - Calculates the index at which a key should be placed
 * on the hash table
 * @key: The key to be hashed and placed on the array
 * @size: overall size of the hash table array
 * Return: The index of the key on hash table array
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash, index;

	hash = hash_djb2(key);
	index = hash % size;

	return (index);
}
