#include "lists.h"

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: length of the string, or 0 if NULL
 */
unsigned int _strlen(const char *s)
{
	unsigned int i = 0;

	if (s == NULL)
		return (0);

	while (s[i])
		i++;

	return (i);
}

/**
 * _strdup - duplicates a string
 * @s: string to duplicate
 *
 * Return: pointer to new string, or NULL on failure
 */
char *_strdup(const char *s)
{
	unsigned int len;
	char *copy;
	unsigned int i;

	if (s == NULL)
		return (NULL);

	len = _strlen(s);
	copy = malloc(len + 1);

	if (copy == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		copy[i] = s[i];

	copy[len] = '\0';

	return (copy);
}

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: double pointer to the head of the list
 * @str: string to store in the new node (will be duplicated)
 *
 * Return: address of the new element, or NULL on failure
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *cur;
	char *dup;

	if (head == NULL)
		return (NULL);

	dup = _strdup(str);
	if (str != NULL && dup == NULL)
		return (NULL);

	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		free(dup);
		return (NULL);
	}

	new->str = dup;
	new->len = (str == NULL) ? 0 : _strlen(dup);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	cur = *head;
	while (cur->next != NULL)
		cur = cur->next;

	cur->next = new;
	return (new);
}
