#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - the entry point for monty
 * @argc: arguments count passed to the program
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on error
 */
int main(int argc, char *argv[])
{
	FILE *file = NULL;
	int exit_code =EXIT_SUCCESS;

	if (argc != 2)
	{
		return (usage_err());
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		return (f_open_err(argv[1]));
	}
	exit_code = run_monty(file);
	fclose(file);

	return (exit_code);
}
