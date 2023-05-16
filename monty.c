#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/* Global variable */
stack_t *stack = NULL;

/* Function implementations */

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
 * op_pall - pall action for monty
 * @stack: pointer to pointer of head's stack
 * @line_number: file's line number
 */

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (stack)
		print_dlistint(*stack);
}

/**
 * op_pint - prints the value at the top of the stack, followed by a new line.
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

void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *aux = *stack;
	
	if(!*stack || !stack || !head->next)
	{
		dprintf(STDERR_FILENO, "L%i: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	head = head->next;
	head->prev = NULL;

	aux->next = head->next;
	head->next = aux;
	(head->next)->prev = head;
	*stack = head;
}
