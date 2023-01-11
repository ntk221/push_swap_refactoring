/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:46:07 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/05 18:08:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <libft.h>
#include <stdio.h>
#include <assert.h>

t_stack *array_to_stack(char *arr, char delim);
/*{
    int     val;
    t_stack *stack = create_stack();
    while(*arr != '\0')
    {
        if(*arr == delim)
        {
            arr++;
            continue;
        }
        val = *arr - '0';
        bool res = push_back(stack, val);
        if (!res)
            return NULL;
        arr++;
    }
    return stack;
}*/

/*void	test_bubble_sort(void)
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
}*/

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

void  test_find_min_node(void)
{
  t_stack *stack_a = create_stack();
  push_back(stack_a, 6);
  push_back(stack_a, 3);
  push_back(stack_a, 2);
  push_back(stack_a, 4);
  push_back(stack_a, 1);
  // print_stack(stack_a);
  int  index = 0;
  t_stack_node *res = find_min_node(stack_a, &index);
  // printf("%d\n", res->val);
  // t_stack_node  *itr = res;
  assert(index == 4);
  while(res != stack_a->head)
  {
    rra(stack_a);
  }
  assert(stack_a->head->val == 1);
  // assert(1 == res);
}

void  test_sort_5(void)
{
  char    *str      = "5 4 3 2 1";
  t_stack *stack_a  = array_to_stack(str, ' ');
  t_stack *stack_b  = create_stack();
  stack_a = sort_5(stack_a, stack_b);
  print_stack(stack_a);
}

void  test_radix_sort(void)
{
  t_stack *a = create_stack();
  t_stack *b = create_stack();
  push_back(a, 0b100);
  push_back(a, 0b000);
  push_back(a, 0b110);
  push_back(a, 0b001);
  push_back(a, 0b101);
  push_back(a, 0b010);
  push_back(a, 0b011);
  a = radix_sort(a, b);
  print_stack(a);
}

int main(void)
{
	// test_bubble_sort();
  test_sort();
  test_sort_5();
  test_sort_3();
  test_find_min_node();
  test_radix_sort();
  // test_find_max_val();
	return (0);
}
