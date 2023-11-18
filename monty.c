#include "monty.h"
/**
 * main - entry point to the program
 * @ac: argument count
 * @av: argument vector
 * Return: 0 always
 *
 */
int main(int ac, char **av)
{
	struct stat file_buff;
	char *line;
	size_t len = 0;
	int line_number = 1;
	FILE *file;

	/*check the number of arguments*/
	if (ac != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		return (EXIT_FAILURE);
	
	}
	if (!isFile(av[1]))
	{
		fprintf(stderr,"Error: %s is not a valid file.\n", av[1]);
		return (EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}
	while (getline(&line, &len, file) != -1)
	{
		printf("%d. %s", line_number, line);
		line_number++;
	}
	fclose(file);
	free(line);
	return (0);
}
