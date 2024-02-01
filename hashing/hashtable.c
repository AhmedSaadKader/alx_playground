#include "hashtable.h"

Ht_item *create_item(char *key, char *value)
{
	Ht_item *item;

	item->key = malloc(strlen(key) + 1);
	item->value = malloc(strlen(value) + 1);
	item = malloc(sizeof(Ht_item));
	strcpy(item->key, key);
	strcpy(item->value, value);
	return (item);
}

HashTable *create_table(int size)
{
	HashTable *table;
	int i = 0;

	table = malloc(sizeof(HashTable));
	table->size = size;
	table->count = 0;
	table->items = calloc(table->size, sizeof(Ht_item));

	for (i = 0; i < table->size; i++)
		table->items[i] = NULL;

	return (table);
}

void free_item(Ht_item *item)
{
	free(item->key);
	free(item->value);
	free(item);
}

void free_table(HashTable *table)
{
	int i = 0;
	Ht_item *item;

	for (int i = 0; i < table->size; i++)
	{
		Ht_item *item = table->items[i];

		if (item != NULL)
			free_item(item);
	}

	free(table->items);
	free(table);
}

void print_table(HashTable *table)
{
	int i = 0;

	printf("\nHash Table\n----------\n");
	for (i = 0; i < table->size; i++)
	{
		if (table->items[i])
			printf("Index:%d, Key: %s, Value:%s\n", i, table->items[i]->key, table->items[i]->value);
	}
	printf("------------\n\n")
}

void handle_collision(HashTable *table, Ht_item *item)
{

}

char *ht_search(HashTable *table, char *key)
{
	int i = 0;
	int index = hash_function(key);
	Ht_item *item = table->items[index];

	if (item != NULL)
	{
		if (strcmp(item->key, key))
			return (item->value);
	}
	return (NULL);
}

void print_search(HashTable *table, char *key)
{
	char *val = ht_search(table, key);

	if (val == NULL)
	{
		printf("Key: %s does not exist\n", key);
		return;
	}
	else
	{
		printf("Key: %s, Value: %s\n", key, val);
	}
}

void ht_insert(HashTable *table, char *key, char *value)
{
	int index = 0;
	Ht_item *current_item, *item;

	item = create_item(key, value);
	index = hash_function(key);
	current_item = table->items[index];
	if (current_item == NULL)
	{
		if (table->count == table->size)
		{
			printf("Insert Error: Hash table is full");
			free_item(item);
			return;
		}
		table->items[index] = item;
		table->count++;
	}
	else
	{
		if (strcmp(current_item->key, key) == 0)
		{
			strcpy(table->items[index]->value, value);
			return;
		}
		else
		{
			handle_collision(table, item);
			return;
		}
	}
}
