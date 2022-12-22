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
#include <assert.h>

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
  
  int *data;
  pop_back(stack_a, &data);
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

  stack_a = create_stack();
  push_back(stack_a, 3);
  push_back(stack_a, 1);
  push_back(stack_a, 2);
  stack_a = sort_3(stack_a);
  print_stack(stack_a);
  destroy_stack(stack_a);

  stack_a = create_stack();
  push_back(stack_a, 1);
  push_back(stack_a, 3);
  push_back(stack_a, 2);
  stack_a = sort_3(stack_a);
  print_stack(stack_a);
  destroy_stack(stack_a);

  stack_a = create_stack();
  push_back(stack_a, 2);
  push_back(stack_a, 3);
  push_back(stack_a, 1);
  stack_a = sort_3(stack_a);
  print_stack(stack_a);
  destroy_stack(stack_a);

}

/*t_stack *sort_5(t_stack *stack_a, t_stack *stack_b);
void  test_sort_5(void)
{
  t_stack *stack_a = create_stack();
  t_stack *stack_b = create_stack();
  push_back(stack_a, 1);
  push_back(stack_a, 6);
  push_back(stack_a, 2);
  push_back(stack_a, 4);
  push_back(stack_a, 5);
  stack_a = sort_5(stack_a, stack_b);
  print_stack(stack_a);
  destroy_stack(stack_a);
}

t_stack *small_partition(t_stack *stack_a, t_stack *stack_b);
void  test_small_partition(void)
{
  t_stack *stack_a = create_stack();
  t_stack *stack_b = create_stack();
  push_back(stack_a, 1);
  push_back(stack_a, 6);
  push_back(stack_a, 2);
  push_back(stack_a, 4);
  push_back(stack_a, 5);
  stack_a = small_partition(stack_a, stack_b);
  print_stack(stack_a);
  destroy_stack(stack_a);
}
*/

/*t_stack_node *find_mid_index(t_stack *stack_a);
void  test_find_mid(void)
{
  t_stack *stack_a = create_stack();
  push_back(stack_a, 1);
  push_back(stack_a, 6);
  push_back(stack_a, 2);
  push_back(stack_a, 4);
  push_back(stack_a, 5);
  t_stack_node *res = find_mid_index(stack_a);
  assert(res->value == 4);
}*/

void  test_find_min_value(void)
{
  t_stack *stack_a = create_stack();
  push_back(stack_a, 1);
  push_back(stack_a, 6);
  push_back(stack_a, 2);
  push_back(stack_a, 4);
  push_back(stack_a, 5);
  // print_stack(stack_a);
  int res = find_min_value(stack_a);
  assert(1 == res);
}

void  test_find_max_value(void)
{
   t_stack *stack_a = create_stack();
  push_back(stack_a, 1);
  push_back(stack_a, 6);
  push_back(stack_a, 2);
  push_back(stack_a, 4);
  push_back(stack_a, 5);
  print_stack(stack_a);
  int res = find_max_value(stack_a);
  assert(res == 6);
}

int main(void)
{
	// test_bubble_sort();
  // test_sort();
  // test_sort_3();
  // test_sort_5();
  test_find_min_value();
  test_find_max_value();
	return (0);
}
