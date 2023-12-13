#define _GNU_SOURCE
#include "monty.h"

inf variables;

/**
  * main - monty main program
  * @argc: variablesument counter
  * @argv: variablesument
  * Return: 0
  */

int main(int argc, char **argv)
{
	char *monty;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	variables_init();

	variables.file = fopen(argv[1], "r");
	if (!variables.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&variables.buff, &variables.size, variables.file) != EOF)
	{
		monty = strtok(variables.buff, " \t\n");
		if (!monty)
		{
			variables.line_number++;
			continue;
		}

		if (monty_exe(monty) == EXIT_FAILURE)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
					variables.line_number, monty);
			memfree();
			fclose(variables.file);
			exit(EXIT_FAILURE);
		}
		variables.line_number++;
	}
	fclose(variables.file);
	memfree();
	exit(EXIT_SUCCESS);
}
