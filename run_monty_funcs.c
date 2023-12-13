#include "monty.h"
#include <string.h>

void (*get_op_func(char *opcode))(stack_t**, unsigned int);

/**
 * get_op_func - matches an opcode with its corresponding function
 * @opcode: opcode to match
 * Return: pointer to the corresponding function
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", monty_push},
		{"pall", monty_pall},
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

