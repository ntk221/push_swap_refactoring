#include "../includes/push_swap.h"

t_stack *create_stack(void)
{
	t_stack *stack;

	stack = (t_stack*)malloc(sizeof(t_stack));
	if (stack == NULL)
		exit(1);
	stack->head = NULL;
	stack->last = NULL;
  stack->index = 0;
	stack->size = 0;
	return (stack);
}

