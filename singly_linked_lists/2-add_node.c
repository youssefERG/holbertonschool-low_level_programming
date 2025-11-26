#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: double pointer to the head of the list
 * @str: string to store in the new node (will be duplicated)
 *
 * Return: address of the new element, or NULL on failure
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
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
	new->next = *head;
	*head = new;

	return (new);
}
