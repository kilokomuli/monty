#include "monty.h"

int usage_err(void);
int malloc_err(void);
int f_open_err(char *filename);
int no_int_err(unsigned int line_number);
/**
 * usage_err -prints usage error
 * Return: EXIT_FAULURE always
 */
int usage_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
/**
 * malloc - prints malloc error message
 * Return : EXIT_FAILURE
 */
int malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
/**
 * f_open_err - prints file opening error messages with filename
 * @filename: Name of file failed to open
 * Return: EXIT_FAILURE
 */
int f_open_err(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}
/**
 * no_int_error - Prints invalid monty_push argument error messages.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * Return: EXIT_FAILURE always.
 */
int no_int_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
