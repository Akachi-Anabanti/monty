#include "monty.h"

/**
 * free_stack - frees the stack
 * @head: pointer to the head of stack
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
