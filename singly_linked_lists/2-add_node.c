#include "lists.h"
/* minimal _strlen and _strdup implementations (non-static) */
unsigned int _strlen(const char *s)
{
    unsigned int i = 0;
    if (!s) return (0);
    while (s[i]) i++;
    return (i);
}

char *_strdup(const char *s)
{
    unsigned int len = _strlen(s);
    char *copy = malloc(len + 1);
    unsigned int i;
    if (!copy) return (NULL);
    for (i = 0; i < len; i++)
        copy[i] = s[i];
    copy[len] = '\0';
    return (copy);
}
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
