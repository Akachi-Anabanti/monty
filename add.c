#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @head: head of the stack
 * @line_number: command of the line number
 *
 */
void _add(stack_t **head, unsigned int line_number)
{
	stack_t *aux;
	int val1, val2, result;

	aux = *head;

	if (aux == NULL || !aux->n || aux->next == NULL
			|| !aux->next->n)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	val1 = aux->n;
	val2 = aux->next->n;
	result = val1 + val2;

	aux->next->prev = NULL;
	aux->next->n = result;
	*head = aux->next;
	free(aux);
}
