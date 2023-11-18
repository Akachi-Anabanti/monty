#include "monty.h"

/**
 * isFile - checks if the argument is a file
 * @path: path to file
 * Return: 0 if not file
 */
int isFile(const char *path)
{
	struct stat path_stat;

	stat(path, &path_stat);

	return (S_ISREG(path_stat.st_mode));
}
/**
 * exec_op - executes the operation
 * @stack: The stack to be manipulated
 * @linenumber: The line number of the operation
 * @op: the opcode
 */
void exec_op(stack_t **stack, unsigned int linenumber, char *op)
{
	size_t i;
	instruction_t instructions[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop}, {"swap", swap},
		{"add", add}, {"nop", nop}, {"sub", sub}, {"div", div}, {"mul", mul},
		{"mod", mod}, {"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl},
		{"rotr", rotr}, {NULL, NULL},
	};

	for (i = 0; i < (sizeof(instructions) / sizeof(instructions[0])); i++)
	{
		if (strcmp(op, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, linenumber);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", linenumber, op);
	exit(EXIT_FAILURE);
}
