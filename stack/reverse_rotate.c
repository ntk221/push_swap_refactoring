/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:49:13 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/06 05:02:20 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*reverse_rotate(t_stack *stack)
{
	int		*data;
	bool	res;

	data = (int *)malloc(sizeof(int));
	res = pop_back(stack, &data);
	if (!res)
		return (NULL);
	res = push_front(stack, *data);
	free(data);
	if (!res)
		return (NULL);
	else
		return (stack);
}

t_stack	*rra(t_stack *stack_a)
{
	t_stack	*result;

	result = reverse_rotate(stack_a);
	if (!result)
		return (result);
	if (write(1, "rra\n", 4))
		return (result);
}

t_stack	*rrb(t_stack *stack_b)
{
	t_stack	*result;

	result = reverse_rotate(stack_b);
	if (!result)
		return (result);
	if (write(1, "rrb\n", 4))
		return (result);
}
