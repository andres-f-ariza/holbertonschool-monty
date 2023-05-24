#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: pointer to pointer of head's stack
 * @line_number: file's line number
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to pointer of head's stack
 * @line_number: file's line number
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		((*stack)->next)->n = (*stack)->n + ((*stack)->next)->n;
		delete_dnodeint_at_index(stack, 0);
	}
}
