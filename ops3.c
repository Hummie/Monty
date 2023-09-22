#include "monty.h"

/**
 * add - handles add
 * @stack: header of stack
 * @line_num: number line
 * Return: void
*/
void add(stack_t **stack, unsigned int line_num)
{
	if (!(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
	}
	sumup(stack);
}

/**
 * sumup - add 2 ints
 * @stack: header pointer
 * Return: void
*/
void sumup(stack_t **stack)
{
	int sum = 0;

	sum = (*stack)->n + (*stack)->next->n;
	add_node_beg(stack, sum);
}
