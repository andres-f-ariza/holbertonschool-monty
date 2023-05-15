#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/* Global variable */
stack_t *stack = NULL;

/* Function implementations */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int value;
	stack_t *new_node;

	arg = strtok(NULL, " \t\n");

	if (!arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
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
