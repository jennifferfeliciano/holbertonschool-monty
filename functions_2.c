#include "monty.h"

/**
 * add - sum all elements within the linked list
 * @stack: head of linked list
 */
void add(stack_t **stack)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "Add error: not enough elements on stack\n");
        exit_with_failure();
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack);
}

/**
 * nop - does nothing
 * @stack: stack
 * @line_number: line from file
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

/**
 * tokenization - tokenizes a string into an array of tokens
 * @ptr: the string to tokenize
 * @delim: the delimiter to split the string
 *
 * Return: an array of tokens, or NULL on failure
 */
char **tokenization(char *ptr, char *delim)
{
	char **tokens = NULL;
	char *token = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * 128);

	if (tokens == NULL)
		return (NULL);

	token = strtok(ptr, delim);
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		if (tokens[i] == NULL)
		{
			free_array(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;

	return (tokens);
}
