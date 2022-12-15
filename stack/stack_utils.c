/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:51:43 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/15 17:02:58 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	int	size;

	size = stack->size;
	puts("--------------------");
	while(size)
	{
		printf("%d\n", stack->head->value);
		rotate(stack);
		size--;
	}
	puts("--------------------");
}