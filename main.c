#include "monty.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define  _GNU_SOURCE

/**
 * main - entry point
 * @ac: args counter
 * @argv: array of args
 * Return: 0
*/

char **opcodes_arr = NULL;

int main(int ac, char **argv)
{
	size_t line_n = 1;
	FILE *fd;
	char *cmd_buffer = NULL;
	stack_t *stack = NULL;
	size_t buffer_size = 0;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		free(cmd_buffer);
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(cmd_buffer, buffer_size, fd) != NULL)
	{
		opcodes_arr = tokenize_line(cmd_buffer);
		execute(&stack, opcodes_arr, line_n);
		line_n++;
	}
	free(cmd_buffer);
	free(opcodes_arr);
	fclose(fd);
	return (0);
}

