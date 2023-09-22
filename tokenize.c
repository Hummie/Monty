#include "monty.h"
#include <string.h>
#include <strings.h>
#include <stdio.h>

/**
 * tokenize_line - tokenizes a read line into an array of strings
 * @command: buffer of the string
 * Return: the array of tokenized strings
*/

char **tokenize_line(char *command)
{
	char *command_cpy, *token_ptr = NULL;
	char **opcode_arr = NULL;
	size_t i = 0, j = 0, num_of_tokens = 0;
	const char *delim = " \n\t";

	if (!command)
		return (NULL);
	command_cpy = _strdup(command);
	token_ptr = strtok(command_cpy, delim);
	while (token_ptr != NULL) /* get num of tokens for correct malloc*/
	{
		num_of_tokens++;
		token_ptr = strtok(NULL, delim); }
	free(command_cpy);
	if (num_of_tokens != 0)
	{
		opcode_arr = malloc(sizeof(char *) * (num_of_tokens + 1));
		if (!opcode_arr)
		{	perror("malloc");
			exit(EXIT_FAILURE); }
		token_ptr = strtok(command, delim);
		while (token_ptr)
		{	opcode_arr[i] = _strdup(token_ptr);
			if (opcode_arr[i] == NULL)
			{
				while (j < i)
					free(opcode_arr[j]), j++;
				free(opcode_arr);
				return (NULL); }
			i++;
			token_ptr = strtok(NULL, delim);
		}
		opcode_arr[i] = NULL;
		return (opcode_arr);
	} return NULL;
}

/**
 * _strdup - duplicates a string to new mem
 * @src: source string
 * Return: pointer to new string
*/
char *_strdup(char *src)
{
	char *dest = NULL;
	unsigned int len = 0;

	if (!src)
		return (NULL);
	len = strlen(src) + 1;
	dest = malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	dest = memcpy(dest, src, len);
	return (dest);
}

/**
 * handle_ac - handles ac error
 * @ac: args counter
 * Return: void
*/
void handle_ac(int ac)
{
	if (ac != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_fd - handles file open error
 * @fd: file descriptor
 * @filename: filename
 * Return: void
*/
void handle_fd(FILE *fd, char *filename)
{
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}
