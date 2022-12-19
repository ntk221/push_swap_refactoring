/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:38:44 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/17 13:33:21 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

t_stack *push(t_stack *src, t_stack *dst)
{
	int		*data;
	bool	ret;

	if (!(src->size > 0))
		return (NULL);
	data = (int *)malloc(sizeof(int));
	if (!data)
		return (NULL);
	ret = pop_front(src, &data);
	if (!ret)
	{
		free(data);
		return (NULL);
	}
	ret = push_front(dst, *data);
	if (!ret)
	{
		free(data);
		return (NULL);
	}
	free(data);
	return (dst);
}

t_stack	*pa(t_stack *stack_a, t_stack *stack_b)
{
	stack_a = push(stack_b, stack_a);
	write(1, "pa\n", 4);
	return (stack_a);
}

t_stack *pb(t_stack *stack_a, t_stack *stack_b)
{
	stack_b = push(stack_a, stack_b);
	write(1, "pb\n", 4);
	return (stack_b);
}
