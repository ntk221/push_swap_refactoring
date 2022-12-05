#include "../includes/push_swap.h"

void	destroy_stack(t_stack *stack)
{
	while(stack->size)
	{
		t_stack_node *next_target = stack->head->next;
		free(stack->head);
		stack->head = next_target;
		stack->size--;
	}
	free(stack);
}