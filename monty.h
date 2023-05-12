#ifndef MONTY_H
#define MONTY_H

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

/*Data structures*/

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Opcodes function prototypes */

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

/* Function prototypes */

void lines_to_array(char *line, char **copy);
void replace_emptylines(char *buff, char **copy);
void initialize_buffer(char *s, int size);
void initialize_array(char **s, int size);
void (*getopcode(char *opcode))(stack_t **, unsigned int);

/** headers **/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

#endif

/* MACROS */
#define OPEN_ERROR(FILE) \
	do {\
	fprintf(stderr, "Error: Can't open file %s\n", FILE);\
	exit(EXIT_FAILURE);\
	} while (0)

#define  INSTRUCTION_ERROR(LINE, INSTRUCTION, STACK) \
	do {\
	fprintf(stderr, "L%d: unknown instruction %s\n", LINE, INSTRUCTION);\
	free_dlistint(STACK);\
	exit(EXIT_FAILURE);\
	} while (0)
