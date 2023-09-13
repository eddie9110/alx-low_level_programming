#include "hash_tables.h"

/**
 * hash_table_print - ftn that prints a hash table.
 * @ht: hash table
 * Return - void
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *hd;
	int hn, flag;

	if (!ht)
		return;

	printf("{");

	for (hn = 0, flag = 0; hn < (int)ht->size; hn++)
	{
		if (flag && ht->array[hn])
			printf(", ");

		for (hd = ht->array[hn]; hd; hd = hd->next)
		{
			printf("'%s': '%s'", hd->key, hd->value);
			if (hd->next)
				printf(", ");
			flag = 1;
		}
	}
	printf("}\n");
}
