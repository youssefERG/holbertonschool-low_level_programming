#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t list
 * @head: pointer to head of list
 * @index: index of the node (starting at 0)
 *
 * Return: pointer to the node at index, or NULL if it does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;
	dlistint_t *cur = head;

	while (cur != NULL)
	{
		if (i == index)
			return (cur);
		cur = cur->next;
		i++;
	}

	return (NULL);
}
