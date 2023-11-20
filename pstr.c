#include "monty.h"

/**
 * _pstr - prints the equivalent of the ASCII
 * @head: The pointer to the head
 * @line_number: The line number of the command
 */
void _pstr(stack_t **head, unsigned int line_number)
{
	stack_t *aux;

	aux = *head;
	if (!aux)
	{
		fprintf(stderr, "L%d: can't pstr, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (aux->n > 127 || aux->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (aux->n != 0 && aux)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}
	printf("\n");
}
