#include "monty.h"

/**
 * _pop - removes the element from the top of the stack
 * @head: Pointer to the head element
 * @line_number: line number of the command
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *aux;

	aux = *head;

	if (aux == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux->next->prev = NULL;
	*head = aux->next;
	free(aux);
}
