#include "monty.h"

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
/**
 * push - inserts a value to a stack_t linked list
 * @stack: pointer to the head node of a stack_t linked list
 * @line_number: current working line number of a monty bytecode file
 */
void push(stack_t **stack,unsigned int line_number)
{
	stack-t *temp, *new_node;
	int i;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		set_op_tok_err(malloc_err());
		return;
	}
	if (op_toks[1] == NULLL)
	{
		set_op_tok_err(no_int_err(line_number));
		return;
	}
	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			set_op_tok_err(no_int_err(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK)
	{
		temp = (*stack)->next;
		new_node->prev = *stack;
		new_node->next = temp;
		if (temp)
			temp->prev = new_node;
		(*stack)->next = new_node;
	}
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		new_node->prev = temp;
		new_node->next = NULL;
		temp->next = new_node;
	}
}
/**
 * pall - prints the value of a stack_t linked list
 * @stack: pointer to the head node
 * @line_number: current working line number of a monty bytecode file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;
	
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void)line_number;
}
