#ifndef MONT_HEADER
#define MONT_HEADER

#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <fcntl.h>
/**
 * struct stack_s - doubly linked list representation of a stack or
 * queue
 * @n: integer
 * @prev: points to the previous element of the stack or queue
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 *
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: fucntion to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct stack_mem
{
	char *stack_value;
} stack_mem_t;

extern stack_mem_t stack_mem;

/*util headers*/
int isFile(const char *path);
bool isInteger(char *str);
void addnode(stack_t **head, int n);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, size_t old_size, size_t new_size);



/*OPCODE headers*/
void _push(stack_t **head, unsigned int line_number);
void _pall(stack_t **head, unsigned int line_number);
void _pint(stack_t **head, unsigned int line_number);
/*void _pop(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);
void _add(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);
void _sub(stack_t **head, unsigned int line_number);
void _div(stack_t **head, unsigned int line_number);
void _mul(stack_t **head, unsigned int line_number);
void _mod(stack_t **head, unsigned int line_number);
void _pchar(stack_t **head, unsigned int line_number);
void _pstr(stack_t **head, unsigned int line_number);
void _rotl(stack_t **head, unsigned int line_number);
void _rotr(stack_t **head, unsigned int line_number);
*/

void exec_op(stack_t **head, unsigned int line_number, char *line_content, FILE *file);
void free_stack(stack_t *head);

#endif
