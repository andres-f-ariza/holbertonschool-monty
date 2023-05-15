#include "monty.h"

/**
 * handle - it handles the program
 * @file: variable char
 */

void handle(char *file)
{
	FILE *fl;
	size_t read = 0;
	int line_number = 1;
	stack_t *head;
	void (*opcode)(stack_t **, unsigned int);

	fl = fopen(file, "r");
	if (!fl)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	head = NULL;

	while (getline(&buff, &read, fl) != -1)
	{
		opcode = getopcode(char);
		if (opcode == NULL)
		{
			dprintf(STDERR_FILENO, "L%i: unknown instruction %s", line_number, buff);
			exit(EXIT_FAILURE);
		}
		opcode(&head, line_number);
		line_number++;
	}
	free(buff);
	fclose(fl);
}
