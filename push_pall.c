#include "monty.h"
/**
 * _push - adds a new element to the top of the stack
 * @stack: stack
 * @line_number: line number
 */

void _push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * _pall - prints all the values on the stack starting from the top
 * @stack: stack
 * @line_number: line number
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *run_stack = *stack;

	(void)line_number;

	while (run_stack != NULL)
	{
		printf("%d\n", run_stack->n);
		run_stack = run_stack->next;
	}
}
