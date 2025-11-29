#include "lists.h"

/**
 * add_dnodeint - adds a node at the beginning of a dlistint_t list
 * @head: pointer to pointer to head of list
 * @n: integer to store
 *
 * Return: address of new node, or NULL on failure
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head != NULL)
		(*head)->prev = new;

	*head = new;
	return (new);
}
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to pointer to head of list
 * @idx: index where the new node should be added (starting at 0)
 * @n: integer for the new node
 *
 * Return: address of the new node, or NULL on failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *cur;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	cur = *h;
	while (cur != NULL && i < idx - 1)
	{
		cur = cur->next;
		i++;
	}

	if (cur == NULL)
		return (NULL);

	if (cur->next == NULL)
		return (add_dnodeint_end(h, n));

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = cur->next;
	new->prev = cur;
	cur->next->prev = new;
	cur->next = new;

	return (new);
}
