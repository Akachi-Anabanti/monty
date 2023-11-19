#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @head: head of stack
 * @line_number: line number of command
 */
void _pint(stack_t **head, unsigned int line_number)
{
	stack_t *aux;

	aux = *head;
	if (aux == NULL || !aux->n)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", aux->n);
}
