#include "monty.h"
#include <stdio.h>

/**
 * add_node_beg - adds a new node to the top of the stack
 * @stack: address of the top node
 * @n: data value
 * Return: void
 */

void add_node_beg(stack_t **stack, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (*stack)
	{
		new_node->n = n;
		new_node->prev = NULL;
		new_node->next = *stack;
		new_node->next->prev = new_node;
		*stack = new_node;
		return;
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;
	*stack = new_node;

	free(new_node);
}

/**
 * del_node_beg - deletes a node at the top of the stack
 * @stack: address to the head of stack
 * @line_num: line number
 * Return: void
 */

void del_node_beg(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	tmp = (*stack);

	if (tmp)
	{
		(*stack) = tmp->next;
		if ((*stack))
			(*stack)->prev = NULL;
		free(tmp);
		return;
	}
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
	exit(EXIT_FAILURE);
}

/**
 * print_int - prints the value of the topmost stack element
 * @stack: top node
 * Return: void
 */

void print_int(stack_t **stack)
{
	if (!*stack) /* runs if the stack is empty */
	{
		return;
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * print_list - prints all the values of the stack
 * @stack: top node
 * Return: void
*/

void print_list(stack_t **stack)
{
	if (!*stack)
	{
		return;
	}
	while ((*stack)->next)
	{
		fprintf(stdout, "%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}
/**
 * nop - does literally nothing
 * @stack: pointer to the head node pointer of stack
 * @line_num: the line number
 * Return: Nothing.
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}
