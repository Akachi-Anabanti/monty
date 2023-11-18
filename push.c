#include "monty.h"
/**
 * push - performs a push operation on a stack
 * @stack: The stack to manipulate
 * @n: the number to add
 */
void push(stack_t **stack, unsigned int n)
{
	stack_t *temp;

	temp =  malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	temp->next = NULL;
	temp->prev = NULL;
	if (stack == NULL || *stack == NULL)
		*stack = temp;
	temp->prev = *stack;
	(*stack)->next = temp;
}
