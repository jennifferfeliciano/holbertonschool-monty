#include "monty.h"

/**
 * push - push a new node to the stack
 * @stack: linked list of nodes
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	int p_int;

	if (tokens[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit_with_failure();
	}

	p_int = atoi(tokens[1]);

	if (p_int == 0 && strcmp(tokens[1], "0") != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit_with_failure();
	}

	stack_t *node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit_with_failure();
	}

	node->n = p_int;
	node->prev = NULL;
	node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = node;
	}

	*stack = node;
}

/**
 * pall - print all on the stack
 * @stack: linked list of nodes
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: linked list of nodes
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit_with_failure();
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - delete node
 * @stack: linked list of nodes
 */
void pop(stack_t **stack)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "Pop error: can't pop an empty stack\n");
		exit_with_failure();
	}

	stack_t *head = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(head);
}
/**
 * swap - swaps the top two elements of the stack
 * @stack: stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *body;

	if (head != NULL && (body = head->next) != NULL)
	{
		int temp = head->n;
		head->n = body->n;
		body->n = temp;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit_with_failure();
	}
}

/**
 * exit_with_failure - Clean up and exit with failure status
 */
void exit_with_failure()
{
	free(tokens[1]);
	free(tokens[0]);
	free(tokens);
	free_listint(*stack);
	free(line);
	fclose(file);
	exit(EXIT_FAILURE);
}
