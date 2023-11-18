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
	return S_ISREG(path_stat.st_mode);
}
