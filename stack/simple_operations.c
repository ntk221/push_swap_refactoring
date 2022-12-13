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

bool	push_front(t_stack *stack,int value)
{
	t_stack_node	*node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (node == NULL)
		return(false);
	node->value = value;
	node->next = stack->head;
	node->prev = NULL;
	if (0 < stack->size) //追加した時に，すでに stack に node が詰まっていたら，その node の prev は新たに追加した head になる
		stack->head->prev = node;
	else
		stack->last = node;
	stack->head = node;
	stack->size += 1;
	return (true);
}

bool	push_back(t_stack *stack, int value)
{
	t_stack_node	*node;
	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (node == NULL)
		return (false);
	node->value = value;
	node->next = NULL;
	node->prev = stack->last;
	if (0 < stack->size)
		stack->last->next = node;
	else
		stack->head = node;
	stack->last = node;
	stack->size += 1;
	return (true);
}
