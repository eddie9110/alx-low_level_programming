#include "hash_tables.h"

/**
 * hash_table_get - Gets value associated with a key from a hash tabe
 * @ht: The hash table to find the key in.
 * @key: The key to be found in hash table.
 * Return: The value associated with the key, or NULL if key was not found.
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *hd;
	int idx;

	if (!ht || !key || !(*key))
		return (NULL);

	idx = key_index((unsigned char *)key, ht->size);
	hd = ht->array[idx];
	
	while (hd)
	{
		if (strcmp(hd->key, key) == 0)
			return (hd->value);
		hd = hd->next;
	}
	return (NULL);
}
