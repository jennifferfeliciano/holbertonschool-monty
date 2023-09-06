#include "monty.h"
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
void swap(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	stack_t *head = *stack;
	stack_t *body;
	int head_value;
	int body_value;

	if (head != NULL)
	{
		body = (*stack)->next;
	}

	if (head != NULL && body != NULL)
	{
		head_value = head->n;
		body_value = body->n;
		head->n = body_value;
		body->n = head_value;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(tokens[1]);
		free(tokens[0]);
		free(tokens);
		free(line);
		free(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}

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
