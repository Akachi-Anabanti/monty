#include "monty.h"

/**
 * isInteger - checks if a string is integer
 * @str: string to check
 * Return: true or false
 */
bool isInteger(char *str)
{
	int len = strlen(str);
	int i = 0;

	(str[i] == '-') ? i++ : i;

	for (; i < len; i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}
/**
 * _realloc - reallocates memory to a pointer
 * @ptr: The pointer
 * @new_size: New size of the pointer
 * @old_size: Old size of the pointer
 * Return: void memory pointer
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	if (ptr != NULL)
	{
		if (old_size > new_size)
			old_size = new_size;
		memcpy(new_ptr, ptr, old_size);
		free(ptr);
	}
	return (new_ptr);
}
