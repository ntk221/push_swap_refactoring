/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:49:38 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/14 03:08:14 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

t_stack	*rotate(t_stack *stack)
{
	int		*data;
	bool	res;

	data = (int*)malloc(sizeof(int));
	res = pop_stack(stack, &data);
	if (!res)
		return (NULL);
	res = pop_stack(stack, &data);
	res = push_back(stack, *data);
	free(data);
	if (!res)
		return (NULL);
	else
		return (stack);
}

t_stack *ra(t_stack *stack_a)
{
	t_stack	*result;

	result = rotate(stack_a);
	if (!result)
		return (result);
	if (write(1, "ra\n", 4))
		return (result);
}

t_stack *rb(t_stack *stack_b)
{
	t_stack *result;

	result = rotate(stack_b);
	if (!result)
		return (result);
	if (write(1, "rb\n", 4))
		return (result);
}
