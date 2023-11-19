#include "monty.h"
/**
 * getline - getline function
 * @lineptr: Pointer to the line content
 * @n: size of the line content
 * @stream: Input stream
 * Return: number of character read
 */
ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
	char *line = *lineptr, *new_line, c;
	size_t i = 0, size;

	if (line == NULL)
	{
		if (*n)
			size = *n;
		else
			size = 25;
		line = malloc(size);
		if (line == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			return (-1);
		}
		*n = size;
	}
	while ((c = fgetc(stream)) != EOF)
	{
		if (i + 1 > *n)
		{
			new_line = _realloc(line, *n, *n * 2);
			if (new_line ==  NULL)
				return (-1);
			line = new_line;
			*n *= 2;
		}

		line[i++] = c;
		if (c == '\n')
			break;
	}
	if (i == 0 && c == EOF)
		return (-1);
	line[i] = '\0';
	*lineptr = line;
	return (i);
}
