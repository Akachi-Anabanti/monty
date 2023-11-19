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
 * isInteger - checks if a string is integer
 * @str: string to check
 * Return: true or false
 */
bool isInteger(char *str)
{
	int len = strlen(str);
	int i = 0;

	(str[i] =='-') ? i++ : i;

	for (; i < len; i++)
	{
		if(!isdigit(str[i]))
			return (false);
	}
	return (true);
}

