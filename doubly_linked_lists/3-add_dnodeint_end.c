#include "lists.h"

/**
 * add_dnodeint_end - adds a node at the end of a dlistint_t list
 * @head: pointer to pointer to head of list
 * @n: integer to store
 *
 * Return: address of new node, or NULL on failure
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *cur;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	cur = *head;
	while (cur->next != NULL)
		cur = cur->next;

	cur->next = new;
	new->prev = cur;

	return (new);
}
