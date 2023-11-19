#include "monty.h"

/**
 * exec_op - executes the operation
 * @stack: The stack to be manipulated
 * @linenumber: The line number of the operation
 * @line_content: The content of the line
 * @file: the file stream
 * Return: 0 is successful else 1
 */
int exec_op(stack_t **stack, unsigned int linenumber,
		char *line_content, FILE *file)
{
	size_t i = 0;
	char *op;

	instruction_t instructions[] = {
		{"push", _push}, {"pall", _pall},
		/**
		 * {"pint", _pint}, {"pop", _pop},{"swap", _swap}, {"add", _add},
		 * {"nop", _nop},
		 * {"sub", _sub},
		 * {"div", _div}, {"mul", _mul}, {"mod", _mod}, {"pchar", _pchar},
		 * {"pstr", _pstr}, {"rotl", _rotl}, {"rotr", _rotr},
		 */
		{NULL, NULL},
	};

	op = strtok(line_content, " \n\t");

	if (op && op[0] == '#')
		return (0);

	/*Assign the value of the stack node*/
	stack_value = strtok(NULL, " \n\t");

	while (instructions[i].opcode && op)
	{
		if (strcmp(op, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, linenumber);
			return (0);
		}
		i++;
	}
	if (op && instructions[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", linenumber, op);
		free(line_content);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	return (1);
}
