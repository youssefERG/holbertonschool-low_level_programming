#include "lists.h"

/**
 * sum_dlistint - returns the sum of all data (n) of a dlistint_t list
 * @head: pointer to head of list
 *
 * Return: sum of node values, 0 if list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *cur = head;

	while (cur != NULL)
	{
		sum += cur->n;
		cur = cur->next;
	}

	return (sum);
}
