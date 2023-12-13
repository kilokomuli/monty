#include "monty.h"

int usage_err(void);
int malloc_err(void);
int f_open_err(char *filename);

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
