/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:29:41 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/21 11:29:42 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

t_stack	*bubble_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		num_of_comparison = stack_a->size;
	int		i;

	while (num_of_comparison)
	{
		i = 0;
		while (i < num_of_comparison)
		{
			if (i == num_of_comparison - 1)
				stack_b = pb(stack_a, stack_b);
			else if (stack_a->head->value < stack_a->head->next->value)
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
	while(stack_b->size)
		stack_a = pa(stack_a, stack_b);
	return (stack_a);
}

t_stack *sort_3(t_stack *stack_a)
{
  int first_value;
  int second_value;
  int third_value;

  first_value = stack_a->head->value;
  second_value = stack_a->head->next->value;
  third_value = stack_a->head->next->next->value;
  if (first_value > second_value < third_value)
    stack_a = sa(stack_a);

  return (stack_a);
}

t_stack *sort(t_stack *stack_a, t_stack *stack_b)
{
	stack_a = bubble_sort(stack_a, stack_b);
	return (stack_a);
}
