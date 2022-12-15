/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:46:07 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/15 17:42:18 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	test_bubble_sort(void)
{
	t_stack *stack = create_stack();
	// t_stack *stack_b = create_stack();
	push_back(stack, 0);
	push_back(stack, -1);
	push_back(stack, 1);
	stack = bubble_sort(stack);
	print_stack(stack);
	destroy_stack(stack);

	stack = create_stack();
	push_back(stack, 4);
	push_back(stack, 2);
	push_back(stack, 7);
	push_back(stack, 1);
	push_back(stack, 3);
	stack = bubble_sort(stack);
	print_stack(stack);
}

int main(void)
{
	test_bubble_sort();
	return (0);
}
