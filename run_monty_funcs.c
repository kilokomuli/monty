#include "monty.h"
#include <string.h>

unsigned int token_arr_len(void);
int empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *file);

/**
 * free_tokens - Frees the global op_toks array of strings.
 */
void free_tokens(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}
/**
 * token_arr_len - Gets the length of current op_toks
 * Return: Length of current op_toks
 */
unsigned int token_arr_len(void)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}
/**
 * empty_line - Checks if a line read from getline only contains delimiters
 * @line: pointer to the line
 * @delims: string of delimeter characters
 * Return: 1 or 0
 */
int empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}
	return (1);
}
/**
 * get_op_func - matches an opcode with its corresponding function
 * @opcode: opcode to match
 * Return: pointer to the corresponding function
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", push},
		{"pall", pall},
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}
	return (NULL);
}

/**
 * run_monty - primary function to execute a monty bytecodes script
 * @file: file descriptor for an open monty bytecodes script
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int run_monty(FILE *file)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prevtok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (empty_line(line, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_err());
		}
		else if (op_toks[0][0] == '#')
		{
			free_tokens();
			continue;
		}
		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_op_error(op_toks[0], line_number);
			free_tokens();
			break;
		}
		prevtok_len = token_arr_len();
		op_func(&stack, line_number);
		if (token_arr_len() != prevtok_len)
		{
			if (op_toks && op_toks[prevtok_len])
				exit_status = atoi(op_toks[prevtok_len]);
			else

				exit_status = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (mallloc_err());
	}
	free(line);
	return (exit_status);
}
