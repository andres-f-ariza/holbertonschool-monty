#include "monty.h"

/**
 * getopcode - gets the function for a given opcode
 * @opcode: operation code to search
 * Return: Pointer to opcode function
 */

void (*getopcode(char *opcode))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t made_opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
	};
	while (i <= 13)
	{
		if (strcmp(made_opcodes[i].opcode, opcode) == 0)
			return (made_opcodes[i].f);
		i++;
	}
	return (NULL);
}
