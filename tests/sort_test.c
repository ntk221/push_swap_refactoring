/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:46:07 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/15 18:36:13 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	test_bubble_sort(void)
{
	t_stack *stack_a = create_stack();
	t_stack *stack_b = create_stack();
	/*push_back(stack, 0);
	push_back(stack, -1);
	push_back(stack, 1);
	stack = bubble_sort(stack);
	print_stack(stack);
	destroy_stack(stack);*/

	stack_a = create_stack();
	push_back(stack_a, 4);
	push_back(stack_a, 2);
	push_back(stack_a, 7);
	push_back(stack_a, 1);
	push_back(stack_a, 3);
	stack_b = bubble_sort(stack_a, stack_b);
	print_stack(stack_b);
}

int main(void)
{
	test_bubble_sort();
	return (0);
}
