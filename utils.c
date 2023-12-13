#include "monty.h"

/**
 * memfree - free allocated memory
 *
 * Return: void
 */

void memfree(void)
{
	if (variables.buff)
		free(variables.buff);

	while (variables.stack)
	{
		stack_t *tmp = variables.stack;

		variables.stack = variables.stack->next;
		free(tmp);
	}
}

/**
  * _isdigit - check if string is digit
  * @str: string to be checked
  *
  * Return: 0 if success otherwise return EXIT_FAILURE
  */

int _isdigit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (i == 0 && str[i] == '-' && str[i + 1])
			continue;
		if (str[i] < 48 || str[i] > 57)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
  * add_node -  add element to stack
  * @head: stack head
  * @n: element to be added
  * Return: (void)
  */

void add_node(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		memfree(), fclose(variables.file);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	new->next = *head;
	if (*head)
	{
		(*head)->prev = new;
	}
	*head = new;
}

/**
  * add_node_end -  add element to queue
  * @head: stack head
  * @n: element to be added
  * Return: (void)
  */

void add_node_end(stack_t **head, const int n)
{
	stack_t *new, *tmp;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		memfree(), fclose(variables.file);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;
	if (!*head)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;

		tmp->next = new;
		new->prev = tmp;
		tmp = NULL;
	}
}
