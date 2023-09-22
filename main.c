#include "monty.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#define  _POSIX_C_SOURCE 200809L
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
	size_t buffer_size = 100;
	int i;

	handle_ac(ac);
	fd = fopen(argv[1], "r");
	handle_fd(fd, argv[1]);
	cmd_buffer = malloc(buffer_size);
	if (!cmd_buffer)
	{
		fprintf(stderr, "malloc failed\n");
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	while (fgets(cmd_buffer, buffer_size, fd))
	{
		opcodes_arr = tokenize_line(cmd_buffer);
		free(cmd_buffer);
		execute(&stack, opcodes_arr, line_n);
		for (i = 0; opcodes_arr[i] != NULL; i++)
			free(opcodes_arr[i]);
		free(opcodes_arr);
		line_n++; }
	free(cmd_buffer);
	free(opcodes_arr);
	fclose(fd);
	return (0);
}

