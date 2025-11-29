#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index index of a dlistint_t
 * @head: pointer to pointer to head of list
 * @index: index of node that should be deleted (starting at 0)
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *cur;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	cur = *head;

	if (index == 0)
	{
		*head = cur->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(cur);
		return (1);
	}

	while (cur != NULL && i < index)
	{
		cur = cur->next;
		i++;
	}

	if (cur == NULL)
		return (-1);

	if (cur->prev != NULL)
		cur->prev->next = cur->next;
	if (cur->next != NULL)
		cur->next->prev = cur->prev;

	free(cur);
	return (1);
}
