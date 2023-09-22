#ifndef MONTY_H
#define MONTY_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern char **opcodes_arr;
void add_node_beg(stack_t **stack, int n);
void del_node_beg(stack_t **stack, unsigned int line_num);
void print_list(stack_t **stack);
void print_int(stack_t **stack);
void pint(stack_t **stack, unsigned int line_num);
void push(stack_t **stack, unsigned int line_num);
void pall(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
char **tokenize_line(char *command);
char *_strdup(char *src);
void execute(stack_t **stack, char **ops_arr, unsigned int line_num);
void nop(stack_t **stack, unsigned int line_num);
void handle_ac(int ac);
void handle_fd(FILE *fd, char *filename);
#endif /* MONTY_H */

