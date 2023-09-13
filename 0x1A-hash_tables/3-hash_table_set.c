#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table.
 * @ht: hash table
 * @key: key
 * @value: value
 * Return: 1 - success, 0 failure
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *n_node = NULL;
	int idx = 0;
	hash_node_t *head = NULL;
	char *cpy_value = NULL;

	if (!ht || !key || *key == '\0' || !value)
		return (0);

	cpy_value = strdup(value);
	if (!cpy_value)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	if (ht->array[idx] && !strcmp(ht->array[idx]->key, key))
	{
		free(ht->array[idx]->value);
		ht->array[idx]->value = cpy_value;
		return (1);
	}
	for (head = ht->array[idx]; head; head = head->next)
	{
		if (!strcmp(head->key, key))
		{
			free(head->value);
			head->value = cpy_value;
			return (1);
		}
	}
	n_node = malloc(sizeof(hash_node_t));
	if (!n_node)
		return (0);
	n_node->key = strdup(key);
	if (!n_node->key)
		return (0);
	n_node->value = cpy_value;
	n_node->next = ht->array[idx];
	ht->array[idx] = n_node;
	return (1);
}
