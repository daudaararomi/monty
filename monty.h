#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * struct argvg - singly linked list representation of arg
 * @arg: integer
 * @flag: integer
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct argvg
{
	int ar;
	int fl;
} argvg_t;

extern argvg_t ar;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct linecon - contains of line and corresponding number
 * @artok: array of tokens read from the line
 * @n: the line number
 *
 * Description: contents of a line and corresponding number
 */
typedef struct linecon
{
	unsigned int n;
	char **artok;
} linecon_t;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stackfile
{
	char *buffer;
	stack_t *stack;
	FILE *file;
} stackfile_t;

/* Important functions */
void (*get_op_func(linecon_t line, stackfile_t *stackfile))(stack_t **, unsigned int);
int _isalpha(int c);

/* file_system functions */
void parse_file(FILE *file);
void tokenline(linecon_t *ln, char *buffer);

/* check functions */
bool check_comment(linecon_t linecon);
bool valid_argument(char *token);
void check_push(linecon_t linecon, stackfile_t *stackfile, char *opcode);

/* Stack manipulation functions */
void push(stack_t **stack, unsigned int nl);
void pall(stack_t **stack, unsigned int nl);
void pint(stack_t **stack, unsigned int nl);
void pop(stack_t **stack, unsigned int nl);
void swap(stack_t **stack, unsigned int nl);
void rotl(stack_t **stack, unsigned int nl);
void rotlop(stack_t **stack, unsigned int nl);
void rotrop(stack_t **stack, unsigned int nl);
void pchar(stack_t **stack, unsigned int nl);
void pstr(stack_t **stack, unsigned int nl);
void free_stack(stack_t **stack);
void nop(stack_t **stack, unsigned int nl);
void qpush(stack_t **stack, unsigned int nl);
void addqu(stack_t **stack, unsigned int nl);
void addst(stack_t **stack, unsigned int nl);

/* Math functions */
void subop(stack_t **stack, unsigned int nl);
void addop(stack_t **stack, unsigned int nl);
void divop(stack_t **stack, unsigned int nl);
void mulop(stack_t **stack, unsigned int nl);
void modop(stack_t **stack, unsigned int nl);

#endif /* MONTY_H */
