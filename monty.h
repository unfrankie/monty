#ifndef MONTY_HEADER
#define MONTY_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
  * struct stack_s - doubly linked list representation of a stack (or queue)
  * @n: integer
  * @prev: points to the previous element of the stack (or queue)
  * @next: points to the next element of the stack (or queue)
  * Description: doubly linked list node structure
  * for stack, queues, LIFO, FIFO
  */

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
  * Description: opcode and its function
  * for stack, queues, LIFO, FIFO
  */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
  * struct inf - opcode info
  * @format: opcode format
  * @buff: opcode buff
  * @line_number: opcode line number
  * @size: opcode size
  * @stack: opcode stack
  * @str: opcode string
  * @file: opcode file
  * Description: opcode info and its function
  * for stack, queues, LIFO, FIFO
  */

typedef struct inf
{
	char *format;
	char *buff;
	int line_number;
	size_t size;
	stack_t *stack;
	instruction_t str[18];
	FILE *file;
} inf;

/*Global variable*/
extern inf variables;

/* Prototypes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void variables_init(void);
void memfree(void);
int _isdigit(char *str);
void add_node(stack_t **head, const int n);
void add_node_end(stack_t **head, const int n);
int monty_exe(char *opcode);

#endif
