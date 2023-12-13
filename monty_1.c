#include "monty.h"

/**
  * add - add top two elements of the stack
  * @stack: stack head
  * @line_number: line number
  * Return: (void)
  */

void add(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		memfree();
		fclose(variables.file);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n = (*stack)->next->n + (*stack)->n;
		pop(stack, line_number);
	}
}

/**
  * nop - nada de nada
  * @stack: stack head
  * @line_number: line number
  * Return: (void)
  */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
  * variables_init - initialize variables
  * Return: void
  */

void variables_init(void)
{
	variables.buff = NULL;
	variables.size = 0;
	variables.line_number = 1;
	variables.stack = NULL;
	variables.format = "LIFO";
	variables.str[0].opcode = "push", variables.str[0].f = push;
	variables.str[1].opcode = "pall", variables.str[1].f = pall;
	variables.str[2].opcode = "pint", variables.str[2].f = pint;
	variables.str[3].opcode = "pop", variables.str[3].f = pop;
	variables.str[4].opcode = "swap", variables.str[4].f = swap;
	variables.str[5].opcode = "add", variables.str[5].f = add;
	variables.str[6].opcode = "nop", variables.str[6].f = nop;
	variables.str[7].opcode = NULL, variables.str[7].f = NULL;
}

/**
  * monty_exe - monty executer
  * @monty: monty
  * Return: 0
  */

int monty_exe(char *monty)
{
	int i;

	if (monty[0] == '#')
	return (EXIT_SUCCESS);

	for (i = 0; variables.str[i].opcode; i++)
	{
		if (strcmp(variables.str[i].opcode, monty) == 0)
		{
			variables.str[i].f(&variables.stack, variables.line_number);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}
