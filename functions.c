#include "monty.h"

/**
 * push - pushes an element onto the stack.
 * @stack: pointer to the stack.
 * @line_number: line number in the Monty bytecode file.
 * @cmd: original command from the file.
 * @fd: file pointer for error handling.
 */
void push(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd)
{
	if (!tokens[1] || !isdigit(*tokens[1]))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		free(cmd);
		free_array(tokens);
		free_stack(*stack);
		fclose(fd);
		exit(EXIT_FAILURE);
	}

	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(cmd);
		free_array(tokens);
		free_stack(*stack);
		fclose(fd);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(tokens[1]);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - print all on the stack
 * @stack: linked list of nodes
 * @line_number: line number for errors
 * @line: pointer to string of getline function
 * @file: file in use
 */
void pall(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	stack_t *temp = *stack;
	(void)line_number;
	(void)line;
	(void)file;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint - prints the value at the top of the stack
 * @stack: linked list of nodes
 * @line_number: line number for errors
 * @line: pointer to string of getline function
 * @file: file in use
 */
void pint(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	(void)line_number;

	if (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free(tokens[1]);
		free(tokens[0]);
		free(tokens);
		free(line);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}
/**
 * pop - delet node
 *
 */
void pop(stack_t **stack, unsigned int line_number, char *line, FILE *file)
{
	stack_t *head = *stack;
	(void)file;
	(void)line;


	if (head != NULL)
	{

		*stack = (*stack)->next;
		if (*stack != NULL)
		{
			(*stack)->prev = NULL;
		}
		free(head);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free(tokens[1]);
		free(tokens[0]);
		free(tokens);
		free(line);
		free(file);
		exit(EXIT_FAILURE);
	}
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
