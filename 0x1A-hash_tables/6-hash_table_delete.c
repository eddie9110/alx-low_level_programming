#include "hash_tables.h"

/**
 * hash_table_delete - a ftn that deletes a hash table.
 * @ht: hash table
 * Return: void
 */


void hash_table_delete(hash_table_t *ht)
{
	int kl;

	for (kl = 0; kl < (int)ht->size; kl++)
	{
		if (ht->array[kl])
			free_list(ht->array[kl]);
	}

	free(ht->array);
	free(ht);
}

/**
 * free_list - a ftn that frees array arr
 * @arr: list
 * Return: void
 */

void free_list(hash_node_t *arr)
{
	hash_node_t *hd = arr;

	while (arr)
	{
		hd = arr;
		free(arr->key);
		free(arr->value);
		free(hd);
		arr = arr->next;
	}
}
