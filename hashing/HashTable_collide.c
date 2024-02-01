#define CAPACITY 50000
#include <stdio.h>
#include "hashtable.h"

unsigned long hash_function(char *str)
{
	unsigned long i = 0;
	int j = 0;

	for (j = 0; str[j]; j++)
		i += str[j];

	return (i % CAPACITY);
}

void main(void)
{
	unsigned long i;

	i = hash_function("Hel");
	printf("%li\n", i);
	printf("%li\n", hash_function("Cau"));
}
