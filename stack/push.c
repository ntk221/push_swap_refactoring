#include "../includes/push_swap.h"

void	push_stack(t_stack *stack_ptr, int value)
{
	t_stack_node	*node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (node == NULL)
		exit(1);
	node->value = value;
	node->prev = stack_ptr->head;
	node->next = NULL;
	if (0 < stack_ptr->size)
		stack_ptr->head->next = node;
	stack_ptr->head = node;
	stack_ptr->size += 1;
}
