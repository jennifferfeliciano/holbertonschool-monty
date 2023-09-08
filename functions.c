#include "monty.h"

/**
 * push - pushes an element onto the stack.
 * @stack: pointer to the stack.
 * @line_number: line number in the Monty bytecode file.
 * @cmd: original command from the file.
 * @fd: file pointer for error handling.
 */
void push(stack_t **stack, unsigned int line_number, char *cmd, FILE *fd
{
	(void) line_number;
	int p_int;

	stack_t *node = malloc(sizeof(stack_t));

	if (node == NULL || tokens[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(tokens[1]);
		free(tokens[0]);
		free(tokens);
		free(cmd);
		free(node);
		free_listint(*stack);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	if (node != NULL)
	{
		if (tokens[1] != NULL)
		{
			p_int = atoi(tokens[1]);
		}

		if (strcmp(tokens[1], "0") != 0 && p_int == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(tokens[1]);
			free(tokens[0]);
			free(tokens);
			free(cmd);
			free(node);
			free_listint(*stack);
			fclose(fd);
			exit(EXIT_FAILURE);
		}
		node->prev = NULL;
		node->n = p_int;
		node->next = (*stack);
		if (node->next != NULL)
		{
			node->next->prev = node;
		}
			*stack = node;
	}

}

/**
 * pall - prints all the values on the stack.
 * @stack: pointer to the stack.
 * @line_number: line number in the Monty bytecode file.
 * @cmd: original command from the file.
 * @fd: file pointer for error handling.
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
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: pointer to the stack.
 * @line_number: line number in the Monty bytecode file.
 * @cmd: original command from the file.
 * @fd: file pointer for error handling.
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
 * pop - removes the top element of the stack.
 * @stack: pointer to the stack.
 * @line_number: line number in the Monty bytecode file.
 * @cmd: original command from the file.
 * @fd: file pointer for error handling.
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
/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to the stack.
 * @line_number: line number in the Monty bytecode file.
 * @cmd: original command from the file.
 * @fd: file pointer for error handling.
 */
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
