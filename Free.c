#include "monty.h"
/**
 * free_listint - free struct
 * @stack: linked list of nodes
 */
void free_listint(stack_t *stack)
{
        stack_t *newnode;

        while (stack != NULL)
        {
                newnode = stack;
                stack = newnode->next;
                free(newnode);
        }
}
