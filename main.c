#include "monty.h"
#include <stdio.h>

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

stack_mem_t stack_mem = {NULL};

/**
 * main - entry point to the program
 * @ac: argument count
 * @av: argument vector
 * Return: 0 always
 *
 */
int main(int ac, char **av)
{
	stack_t *stack = NULL;
	char *line_content = NULL;
	int line_number = 1;
	FILE *file;
	size_t size = 0;
	ssize_t nread = 1;

	/*check the number of arguments*/
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (!isFile(av[1]))
	{
		fprintf(stderr, "Error: Can't open file %s.\n", av[1]);
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (nread > 0)
	{
		line_content = NULL;
		nread = getline(&line_content, &size, file);
		if (nread > 0)
		{
			exec_op(&stack, line_number, line_content, file);
			line_number++;
		}
		free(line_content);
	}
	fclose(file);
	free_stack(stack);
	return (0);
}
