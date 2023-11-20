#include "monty.h"

/**
 * _pstr - prints the equivalent of the ASCII
 * @head: The pointer to the head
 * @line_number: The line number of the command
 */
void _pstr(stack_t **head, unsigned int line_number)
{
	stack_t *aux;

	(void)line_number;
	aux = *head;
	while (aux)
	{
		if (aux->n > 127 || aux->n <= 0)
			break;
		printf("%c", aux->n);
		aux = aux->next;
	}
	printf("\n");
}
