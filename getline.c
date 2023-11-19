#include "monty.h"
/**
 * getline - getline function for c 89
 * @buffer: The text buffer
 * @size: the size of the string
 * @stream: The file stream
 * Return: buffer
 */
char *getline(char *buffer, int size, FILE *stream)
{
	if (fgets(buffer, size, stream) != NULL)
	{
		return (buffer);
	}
	return (NULL);
}
