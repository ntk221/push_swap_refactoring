/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:46:07 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/17 13:35:52 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	test_bubble_sort(void)
{
	t_stack *stack_a = create_stack();
	t_stack *stack_b = create_stack();
	push_back(stack_a, 0);
	push_back(stack_a, -1);
	push_back(stack_a, 1);
	stack_a = bubble_sort(stack_a, stack_b);
	print_stack(stack_a);
	destroy_stack(stack_a); 
	destroy_stack(stack_b);

	stack_a = create_stack();
	stack_b = create_stack();
	push_back(stack_a, 4);
	push_back(stack_a, 2);
	push_back(stack_a, 7);
	push_back(stack_a, 1);
	push_back(stack_a, 3);
	stack_a = bubble_sort(stack_a, stack_b);
	print_stack(stack_a);
	destroy_stack(stack_a); 
	destroy_stack(stack_b);

	stack_a = create_stack();
	stack_b = create_stack();
	push_back(stack_a, 0);
	push_back(stack_a, 1);
	push_back(stack_a, -1);
	push_back(stack_a, -1);
	push_back(stack_a, 1);
	stack_a = bubble_sort(stack_a, stack_b);
	print_stack(stack_a);
	// print_stack(stack_a);
	destroy_stack(stack_a); 
	destroy_stack(stack_b);

  stack_a = create_stack();
  stack_b = create_stack();
  push_back(stack_a, 3);
  push_back(stack_a, 2);
  push_back(stack_a, 1);
  stack_a = sort(stack_a, stack_b);
  print_stack(stack_a);
  destroy_stack(stack_a);
  destroy_stack(stack_b);
}

void  test_sort()
{
  t_stack *stack_a = create_stack();
  t_stack *stack_b = create_stack();
  push_back(stack_a, 3);
  push_back(stack_a, 2);
  push_back(stack_a, 1);
  stack_a = sort(stack_a, stack_b);
  print_stack(stack_a);
  destroy_stack(stack_a);
  destroy_stack(stack_b);
}

void  test_sort_3()
{
  t_stack *stack_a = create_stack();

  push_back(stack_a, 2);
  push_back(stack_a, 1);
  push_back(stack_a, 3);
  stack_a = sort_3(stack_a);
  print_stack(stack_a);
  destroy_stack(stack_a);
  
  stack_a = create_stack();
  push_back(stack_a, 3);
  push_back(stack_a, 2);
  push_back(stack_a, 1);
  stack_a = sort_3(stack_a);
  print_stack(stack_a);
  destroy_stack(stack_a);
}

int main(void)
{
	// test_bubble_sort();
  // test_sort();
  test_sort_3();
	return (0);
}
