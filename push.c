#include "monty.h"

/**
 * _push - performs a push operation on a stack
 * @stack: The stack to manipulate
 * @line_number: the number to add
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int n;

	if (!isInteger(stack_mem.stack_value))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	n = atoi(stack_mem.stack_value);
	addnode(stack, n);
}
