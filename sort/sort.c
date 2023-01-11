/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:29:41 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/06 08:16:18 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

/*t_stack	*bubble_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		num_of_comparison;
	int		i;

	num_of_comparison = stack_a->size;
	while (num_of_comparison)
	{
		i = 0;
		while (i < num_of_comparison)
		{
			if (i == num_of_comparison - 1)
				stack_b = pb(stack_a, stack_b);
			else if (stack_a->head->val < stack_a->head->next->val)
			{
				stack_a = sa(stack_a);
				stack_a = ra(stack_a);
			}
			else
				stack_a = ra(stack_a);
			i++;
		}
		num_of_comparison--;
	}
	while (stack_b->size)
		stack_a = pa(stack_a, stack_b);
	return (stack_a);
}*/

t_stack	*radix_sort(t_stack *a, t_stack *b)
{
	size_t	max_bits;
	size_t	size;
	size_t	i;
	size_t	j;

	max_bits = 0;
	while ((a->size - 1) >> max_bits != 0)
		max_bits++;
	size = a->size;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((a->head->val >> i) & 1) == true)
				a = ra(a);
			else
				b = pb(a, b);
		}
		while (b->size != 0)
			a = pa(a, b);
		i++;
	}
	return (a);
}

t_stack	*sort_3(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->head->val;
	second = stack_a->head->next->val;
	third = stack_a->head->next->next->val;
	if (first > second && second < third && third > first)
		stack_a = sa(stack_a);
	else if (first > second && second > third && third < first)
	{
		stack_a = sa(stack_a);
		stack_a = rra(stack_a);
	}
	else if (first > second && second < third && third < first)
		stack_a = ra(stack_a);
	else if (first < second && second > third && third > first)
	{
		stack_a = sa(stack_a);
		stack_a = ra(stack_a);
	}
	else if (first < second && second > third && third < first)
		stack_a = rra(stack_a);
	return (stack_a);
}

t_stack	*sort_5(t_stack *stack_a, t_stack *stack_b)
{
	size_t			id;
	t_stack_node	*min;
	bool			flag;

	flag = false;
	if (stack_a->size == 5)
	{
		id = 0;
		min = find_min_node(stack_a, &id);
		while (min != stack_a->head)
		{
			if (id < stack_a->size / 2)
				stack_a = ra(stack_a);
			else
				stack_a = rra(stack_a);
		}
		stack_b = pb(stack_a, stack_b);
		flag = true;
	}
	stack_a = sort_4(stack_a, stack_b);
	if (flag)
		stack_a = pa(stack_a, stack_b);
	return (stack_a);
}

t_stack	*sort_4(t_stack *stack_a, t_stack *stack_b)
{
	size_t			id;
	t_stack_node	*min;

	id = 0;
	min = find_min_node(stack_a, &id);
	while (min != stack_a->head)
	{
		if (id < stack_a->size / 2)
			stack_a = ra(stack_a);
		else
			stack_a = rra(stack_a);
	}
	stack_b = pb(stack_a, stack_b);
	stack_a = sort_3(stack_a);
	stack_a = pa(stack_a, stack_b);
	return (stack_a);
}

t_stack	*sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sa(stack_a);
	else if (stack_a->size == 3)
		stack_a = sort_3(stack_a);
	else if (stack_a->size == 5 || stack_a->size == 4)
		stack_a = sort_5(stack_a, stack_b);
	else
		stack_a = radix_sort(stack_a, stack_b);
	return (stack_a);
}
