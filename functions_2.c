#include "monty.h"

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
 * swap - swaps the top two elements of the stack
 * @stack: stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *head = *stack;
    stack_t *body;

    if (head == NULL || (body = head->next) == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit_with_failure();
    }

    int temp = head->n;
    head->n = body->n;
    body->n = temp;
}

/**
 * tokenization - extract tokens from the getline command
 * @ptr: String of the command line
 * @delim: Delimiter
 * Return: the array of tokens
 */
char **tokenization(char *ptr, char *delim)
{
    char **tokens = NULL;
    char *token = strtok(ptr, delim);
    int i = 0;

    tokens = malloc(sizeof(char *) * 10);

    while (token)
    {
        tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, delim);
    }

    tokens[i] = NULL;
    return tokens;
}

void (*get_op_func(char **tokens))(stack_t **stack, unsigned int line_number)
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

    for (int i = 0; in_fun[i].opcode != NULL; i++)
    {
        if (strcmp(tokens[0], in_fun[i].opcode) == 0)
        {
            return in_fun[i].f;
        }
    }

    return in_fun[7].f; // Default to unkn_func
}

/**
 * unkn_func - print error message and free memory
 * @stack: stack
 * @line_number: number of line
 */
void unkn_func(stack_t **stack, unsigned int line_number)
{
    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tokens[0]);
    exit_with_failure();
}
