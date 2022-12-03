#include "../includes/push_swap.h"

int	pop_stack(t_stack *stack)
{
	t_stack_node	*head;
	t_stack_node	*new_head;
	int		ret;

	if (0 < stack->size)
	{
		head = stack->head;
		new_head = head->prev;
		ret = head->value;
		free(head);
		if (head->prev != NULL)
			new_head->prev = NULL;
		stack->head = new_head;
		stack->size -= 1;
		return (ret);
	}
}

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
