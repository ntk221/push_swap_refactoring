/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 05:03:33 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/06 05:05:48 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdbool.h>

bool	pop_front(t_stack *stack, int **data)
{
	t_stack_node	*head;
	t_stack_node	*new_head;

	if (1 == stack->size)
	{
		**data = stack->head->val;
		free(stack->head);
		stack->head = NULL;
		stack->size--;
		return (true);
	}
	else if (0 < stack->size)
	{
		head = stack->head;
		new_head = head->next;
		**data = head->val;
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
		**data = stack->last->val;
		free(stack->last);
		stack->last = NULL;
		stack->size--;
		return (true);
	}
	else if (0 < stack->size)
	{
		last = stack->last;
		new_last = last->prev;
		**data = last->val;
		free(last);
		stack->last = new_last;
		stack->size--;
		return (true);
	}
	return (false);
}

bool	push_front(t_stack *stack, int val)
{
	t_stack_node	*node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (node == NULL)
		return (false);
	node->val = val;
	node->next = stack->head;
	node->prev = NULL;
	if (0 < stack->size)
		stack->head->prev = node;
	else
		stack->last = node;
	stack->head = node;
	stack->size++;
	return (true);
}

bool	push_back(t_stack *stack, int val)
{
	t_stack_node	*node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	node->val = val;
	node->next = NULL;
	if (stack->last != NULL)
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
	printf("%d\n", stack->head->val);
	printf("%d\n", stack->head->next->val);
	printf("%d\n", stack->last->val);
	printf("%d\n", stack->last->prev->val);

}*/
