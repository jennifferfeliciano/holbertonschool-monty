#include"monty.h"
/**
 * main - interpreter of monty
 * @ac: counting of arguments
 * @av: vector of arguments
 * Return: always 0
 */

int main(int ac, char **av)
{
	FILE *file;
	char *line = NULL;
	size_t buffline = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	/* CHECKING NUMBER OF ARGUMENTS */
	if (ac != 2)
		exit(EXIT_FAILURE);

	if (av[1] == NULL)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* OPENING FILE */
	file = fopen(av[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit (EXIT_FAILURE);
	}

	/* GETTING TEXT LINE OF OPEN FILE */
	while (getline(&line, &buffline, file) != -1)
	{
		/* TOKENIZATION */
		tokens = tokenization(line, " \n");
		if (tokens[0] != NULL || tokens[1] != NULL)
		{
			/* COMPARE TOKEN AND CALL FUNCTION */
			get_op_func(tokens)(&stack, line_number, line, file);
			/* COUNT LINES OF THE FILE PROCESS */
			line_number++;
		}
		free(tokens[1]);
		free(tokens[0]);
		free(tokens);
	}
	free_listint(stack);
	free(line);
	fclose(file);
	return (0);
}