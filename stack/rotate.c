/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:49:38 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/13 13:10:27 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*rotate(t_stack *stack)
{
	int		*data;
	bool	res;
	t_stack *new;

	data = (int*)malloc(sizeof(int));
	res = pop_stack(stack, &data);
	if (!res)
		exit(1);
	res = push_back(stack, *data);
	if (!res)
		return (NULL);
	else
		return (stack);
}