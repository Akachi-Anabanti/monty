#include "monty.h"

/**
 * _div - divides the top two elements of the stack
 * @head: head of the stack
 * @line_number: command of the line number
 *
 */
void _div(stack_t **head, unsigned int line_number)
{
	stack_t *aux;
	int val1, val2, result;

	aux = *head;

	if (aux == NULL || aux->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	val1 = aux->n;
	if (val1 == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	val2 = aux->next->n;
	result = val2 / val1;

	aux->next->prev = NULL;
	aux->next->n = result;
	*head = aux->next;
	free(aux);
}
