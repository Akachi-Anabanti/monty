#include "monty.h"

/**
 * addnode - adds a node to the head of the stack
 * @head: head of the stack
 * @n: the new value
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: cannot malloc\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}
