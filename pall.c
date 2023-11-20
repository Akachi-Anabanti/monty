#include "monty.h"

/**
 * _pall - prints all the values of the stack
 * @head: pointer to head of the stack
 * @line_number: The line number of the file
 */
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *head;

	if (temp == NULL) /*|| !temp->n)*/
		return;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
