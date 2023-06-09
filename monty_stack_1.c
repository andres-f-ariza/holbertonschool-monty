#include "monty.h"

/**
 * push - push action for monty
 * @stack: pointer to pointer of head's stack
 * @line_number: file's line number
 */

void push(stack_t **stack, unsigned int line_number)
{
	int value_to_add = 0, isint;
	char *value;

	value = strtok(NULL, " ");
	isint = string_is_int(value);
	if (isint == 0)
	{
		value_to_add = atoi(value);
		add_dnodeint(stack, value_to_add);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - pall action for monty
 * @stack: pointer to pointer of head's stack
 * @line_number: file's line number
 */

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (stack)
		print_dlistint(*stack);
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: pointer to pointer of head's stack
 * @line_number: file's line number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack.
 * @stack: pointer to pointer of head's stack
 * @line_number: file's line number
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
		delete_dnodeint_at_index(stack, 0);
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to pointer of head's stack
 * @line_number: file's line number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int aux_value;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		aux_value = (*stack)->n;
		(*stack)->n = ((*stack)->next)->n;
		((*stack)->next)->n = aux_value;
	}
}
