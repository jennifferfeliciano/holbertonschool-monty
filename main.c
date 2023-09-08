#include"monty.h"
/**
 * main - interpreter of monty
 * @ac: counting of arguments
 * @av: vector of arguments
 * Return: always 0
 */

int main(int ac, char **av)
{
	FILE *fd;
	char *cmd = NULL;
	size_t buffline = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if (ac != 2)
		exit(EXIT_FAILURE);

	if (av[1] == NULL)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	
	fd = fopen(av[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit (EXIT_FAILURE);
	}

	while (getline(&cmd, &buffline, fd) != -1)
	{
		tokens = tokenization(cmd, " \n");
		if (tokens[0] != NULL || tokens[1] != NULL)
		{
			get_op_func(tokens)(&stack, line_number, cmd, fd);
			line_number++;
		}
		free(tokens[1]);
		free(tokens[0]);
		free(tokens);
	}
	free_listint(stack);
	free(cmd);
	fclose(fd);
	return (0);
}
