#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * push - adds a node to a stack or queue
 * @stack: pointer to the topmost element
 * @line_num: line number
 * Return: void
*/

void push(stack_t **stack, unsigned int line_num)
{
	unsigned int n;

	if (!opcodes_arr[1])
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	n = atoi(opcodes_arr[1]);
	add_node_beg(stack, n);
}

/**
 * pall - prints all data values of a stack
 * @stack: address of the topmost element
 * @line_num: line number
 * Return: void
*/
void pall(stack_t **stack, unsigned int line_num)
{
	(void)line_num;
	print_list(stack);
}

/**
 * pint - prints the value of the top of the stack
 * @stack: address to the topmost element
 * @line_num: line number
 * Return: void
*/
void pint(stack_t **stack, unsigned int line_num)
{
	(void)line_num;
	print_int(stack);
}

/**
 * pop - removes the top element of the stack
 * @stack: address to the top node
 * @line_num: line number
 * Return: void
*/
void pop(stack_t **stack, unsigned int line_num)
{
	del_node_beg(stack, line_num);
}


/**
 * execute - handles the pairing of an oppcode and  a function
 * @ops_arr: array with opcodes
 * @line_num: line number
 * @stack: address of the head node
*/

void execute(stack_t **stack, char **ops_arr, unsigned int line_num)
{
	unsigned int i = 0;
	int found_opcode = 0;

	instruction_t operate[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{NULL, NULL}
	};

	while (operate[i].opcode)
	{
		if ((strcmp(ops_arr[0], operate[i].opcode) == 0))
		{
			operate[i].f(stack, line_num);
			found_opcode = 1;
			break;
		}
		i++;
	}
	if (!found_opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, ops_arr[0]);
		exit(EXIT_FAILURE);
	}

}

