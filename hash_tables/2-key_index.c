#include "hash_tables.h"

/**
 * key_index - Gives index of a key
 * @key: The key (string)
 * @size: Size of hash table array
 *
 * Return: Index where key/value should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
