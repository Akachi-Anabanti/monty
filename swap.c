#include "monty.h"

/**
 * _swap - swaps top and next element
 * @head: pointer to the top of stack
 * @line_number: command line number
 */
void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp, *next_node;

	temp = *head;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	next_node = temp->next;
	temp->next = next_node->next;
	if (temp->next != NULL)
		temp->next->prev = temp;

	next_node->prev = NULL;
	next_node->next = temp;
	*head = next_node;
}
