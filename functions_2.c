#include "monty.h"
/**
 * sum - summ all elements with in linked list
 * @stack: head of linked list
 * Return: sum of elements
 */
void add(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	int sum;
	(void)line_number;
	(void)line;
	(void)file;

	sum = (*stack)->n + (*stack)->next->n;
	*stack = (*stack)->next;
	(*stack)->n = sum;
	free((*stack)->prev);

		/*sum += (*stack)->next->n;
		*stack = (*stack)->next;*/
}

/**
 * nop - does nothing
 * @stack: stack
 * @line_number: line from file
 * @line: pointer to line
 * @file: file opened
 */
void nop(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	(void)stack;
	(void)line_number;
	(void)line;
	(void)file;
}
char **tokens = NULL;
/**
 * tokenization - extract tokens from the getline command
 *
 * @ptr: String of the command line
 * @delim: Delimiter
 *
 * Return: the array of tokens
 *
 * Description: We first allocate space for the array of tokens. 
 */
char **tokenization(char *ptr, char *delim)
{
	char *token = NULL, **tokens = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * 10);
	token = strtok(ptr, delim);

	while (token)
	{
		tokens[i] = malloc(sizeof(char) * strlen(token) + 1);
		strcpy(tokens[i], token);
		i++;
		token = NULL;
		token = strtok(NULL, delim);
	}

	tokens[i] = NULL;
	free(token);
	return (tokens);
}

void (*get_op_func(char **tokens))(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	static instruction_t in_fun[] = {
    {"push", push},
    {"pall", pall},
    {"pint", pint},
    {"add", add},
    {"nop", nop},
    {"pop", pop},
    {"swap", swap},
    {NULL, unkn_func},
};

	int i = 0;

	
	while (i < 7)
	{
		if (strcmp(tokens[0], in_fun[i].opcode) == 0)
		{
			return (in_fun[i].f);
		}
		i++;
	}
	return (in_fun[i].f);
}
/**
 * unkn_func - print error message and free memory
 * @stack: stack
 * @line_number: number of line
 * @line: pointer to line
 * @file: opened file
 */
void unkn_func(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tokens[0]);
	free(tokens[1]);
	free(tokens[0]);
	free(tokens);
	free(line);
	free_listint(*stack);
	fclose(file);
	exit(EXIT_FAILURE);
}
