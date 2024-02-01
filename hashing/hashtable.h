#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stddef.h>
#include <string.h>
#include <stdio.h>

typedef struct Ht_item
{
char *key;
char *value;
} Ht_item;

typedef struct HashTable
{
Ht_item **items;
int size;
int count;
} HashTable;

unsigned long hash_function(char *str);
Ht_item *create_item(char *key, char *value);
HashTable *create_table(int size);
void free_item(Ht_item *item);
void free_table(HashTable *table);
void print_table(HashTable *table);
void handle_collision(HashTable *table, Ht_item *item);
void ht_insert(HashTable *table, char *key, char *value);

#endif
