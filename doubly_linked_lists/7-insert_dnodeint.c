#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to pointer to head of the list
 * @idx: index where the new node should be added (starts at 0)
 * @n: value to store in the new node
 *
 * Return: address of the new node, or NULL on failure or if index is invalid
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *curr, *new_node;
	unsigned int i;

	if (h == NULL)
		return (NULL);

	/* insert at head */
	if (idx == 0)
		return (add_dnodeint(h, n));

	/* traverse to node at index - 1 */
	curr = *h;
	for (i = 0; curr != NULL && i < idx - 1; i++)
		curr = curr->next;

	/* idx is out of range */
	if (curr == NULL)
		return (NULL);

	/* if inserting at the end (curr is last) */
	if (curr->next == NULL)
		return (add_dnodeint_end(h, n));

	/* insert in middle */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = curr->next;
	new_node->prev = curr;
	curr->next->prev = new_node;
	curr->next = new_node;

	return (new_node);
}
