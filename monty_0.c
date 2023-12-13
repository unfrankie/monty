#include "monty.h"

/**
  * push - pushe element to the stack
  * @stack: stack head
  * @line_number: line number
  * Return: (void)
  */

void push(stack_t **stack, unsigned int line_number)
{
	char *number = strtok(NULL, " \t\n");

	if (!number || _isdigit(number) == EXIT_FAILURE)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		memfree();
		fclose(variables.file);
		exit(EXIT_FAILURE);
	}

	if (strcmp(variables.format, "FIFO") == 0) /*Queue*/
		add_node_end(stack, atoi(number));
	else /* Stack */
		add_node(stack, atoi(number));
}

/**
  * pall - print all values on the stack
  * @stack: stack head
  * @line_number: line number
  * Return: (void)
  */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	(void)line_number;

	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
  * pint - print value at the top of the stack
  * @stack: stack head
  * @line_number: line number
  * Return: (void)
  */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		memfree();
		fclose(variables.file);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
  * pop - remove top element of the stack
  * @stack: stack head
  * @line_number: line number
  * Return: (void)
  */

void pop(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		memfree();
		fclose(variables.file);
		exit(EXIT_FAILURE);
	}

	if (!(*stack)->next)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
}

/**
  * swap - swap top two elements of the stack
  * @stack: stack head
  * @line_number: line number
  * Return: (void)
  */

void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		memfree();
		fclose(variables.file);
		exit(EXIT_FAILURE);
	}
	else
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
}
