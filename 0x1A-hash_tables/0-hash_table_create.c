#include "hash_tables.h"

/**
 * hash_table_create - a ftn to create a hash table.
 * @size: size of the array
 * Return: pointer to the new hash table or NULL
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *n_table;
	unsigned long int ko;

	n_table = malloc(sizeof(hash_table_t));

	if (n_table == NULL)
		return (NULL);

	n_table->size = size;

	n_table->array = malloc(sizeof(hash_node_t *) * size);

	if (n_table->array == NULL)
		return (NULL);

	for (ko = 0; ko < size; ko++)
		n_table->array[ko] = NULL;

	return (n_table);
}
