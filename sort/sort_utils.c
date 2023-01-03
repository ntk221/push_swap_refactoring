/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:10:47 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/04 03:34:30 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

t_stack_node	*find_min_node(t_stack *stack_a, int *index)
{
	t_stack_node	*min;
	int				size;
	t_stack_node	*itr;
	size_t			id;

	itr = stack_a->head;
	min = itr;
	size = stack_a->size;
	id = 0;
	while (size)
	{
		if (min->val > itr->val)
		{
			min = itr;
			*index = id;
		}
		itr = itr->next;
		size--;
		id++;
	}
	return (min);
}

t_stack_node	*find_max_node(t_stack *stack_a)
{
	t_stack_node	*max;
	int				size;
	t_stack_node	*itr;

	itr = stack_a->head;
	max = itr;
	size = stack_a->size;
	while (size)
	{
		if (max->val < itr->val)
		max = itr;
		itr = itr->next;
		size--;
	}
	return (max);
}
