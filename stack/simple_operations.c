#include "../includes/push_swap.h"
#include <stdbool.h>

// 引数に受け取る data は malloc で用意する
bool	pop_stack(t_stack *stack, int **data)
{
	t_stack_node	*head;
	t_stack_node	*new_head;

	if (0 < stack->size)
	{
		head = stack->head;
		new_head = head->next;
		**data = head->value;
		free(head);
		if (head->next != NULL)
			new_head->next = NULL;
		stack->head = new_head;
		stack->size -= 1;
		return (true);
	}
	return (false);
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
