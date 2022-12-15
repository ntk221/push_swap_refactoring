#include "../includes/push_swap.h"
#include <stdbool.h>

// 引数に受け取る data は malloc で用意する
bool	pop_front(t_stack *stack, int **data)
{
	t_stack_node	*head;
	t_stack_node	*new_head;

	if (1 == stack->size)
	{
		**data = stack->head->value;
		free(stack->head);
		stack->head = NULL;
		stack->size--;
		return (true);
	}
	else if (0 < stack->size)
	{
		head = stack->head;	
		new_head = head->next;
		**data = head->value;
		free(head);
		stack->head = new_head;
		stack->size--;
		return (true);
	}
	return (false);
}

bool	pop_back(t_stack *stack, int **data)
{
	t_stack_node	*last;
	t_stack_node	*new_last;

	if (1 == stack->size)
	{
		**data = stack->last->value;
		free(stack->last);
		stack->last = NULL;
		stack->size--;
		return (true);
	}
	else if (0 < stack->size)
	{
		last = stack->last;
		new_last = last->prev;
		**data = last->value;
		free(last);
		stack->last = new_last;
		stack->size--;
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
	stack->size++;
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
	stack->size++;
	return (true);
}

/*#include <stdio.h>
int main()
{
	t_stack *stack = create_stack();
	push_back(stack, 1);
	push_back(stack, 2);
	push_back(stack, 3);
	int	*data = malloc(sizeof(int));
	bool res = pop_stack(stack, &data);
	free(data);
	printf("%d\n", stack->head->value);
	printf("%d\n", stack->head->next->value);
	printf("%d\n", stack->last->value);
	printf("%d\n", stack->last->prev->value);

}*/