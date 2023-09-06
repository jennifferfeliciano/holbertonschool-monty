#include "monty.h"

int main(int ac, char **av)
{
	FILE *file;
	char *line = NULL;
	size_t buffline = 0;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &buffline, file) != -1)
	{
		char **tokens = tokenization(line, " \n");
		if (tokens[0])
		{
			get_op_func(tokens)(&stack, line_number++, line, file);
			free(tokens[1]);
			free(tokens[0]);
			free(tokens);
		}
	}

	free_listint(stack);
	free(line);
	fclose(file);
	return (0);
}
