/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:49:13 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/15 09:51:49 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

t_stack *reverse_rotate(t_stack *stack)
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
		return(NULL);
	else
		return (stack);
}