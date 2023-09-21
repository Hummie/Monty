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
	char *command_cpy = NULL, *token_ptr = NULL;
	char **opcode_arr = NULL;
	size_t i = 0, j = 0, num_of_tokens = 0;
	const char *delim = " \n\t";

	strcpy(command_cpy, command);
	token_ptr = strtok(command_cpy, delim);
	while (token_ptr != NULL) /* get num of tokens for correct malloc*/
	{
		num_of_tokens++;
		token_ptr = strtok(NULL, delim);
	}
	free(command_cpy);

	if (num_of_tokens != 0)
	{
		opcode_arr = malloc(sizeof(char *) * (num_of_tokens + 1));
		if (!opcode_arr)
		{
			perror("malloc");
			exit(EXIT_FAILURE);	
		}
		token_ptr = strtok(command, delim);
		while (token_ptr)
		{
			strcpy(opcode_arr[i], token_ptr);
			if (opcode_arr[i] == NULL)
			{
				while (j < i)
					free(opcode_arr[j]), j++;
				free(opcode_arr);
				return (NULL);
			}
			i++;
			token_ptr = strtok(NULL, delim);
		}
		opcode_arr[i] = NULL;
		return (opcode_arr);
	}
	return NULL;
}
