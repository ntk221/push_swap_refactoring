/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:51:43 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/18 16:29:07 by kazuki           ###   ########.fr       */
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

t_stack	*initialize_stack_a(t_stack *stack_a, int argc, char **argv)
{
	int		i;
	int		num;
	bool	res;
	bool	error;

	i = 1;
	stack_a = create_stack();
	while(i < argc)
	{
		error = true;
		num = ft_atoi(argv[i], &error);
		if (error)
			exit(1);
		res = push_back(stack_a, num);
		if (!res)
			exit(1);
		i++;
	}
	return (stack_a);
}

bool  is_sorted(t_stack *stack)
{
  t_stack_node *head;

  if (stack->head == NULL)
    return (true);
  head = stack->head;
  while (head->next != NULL)
  {
    if (head->value > head->next->value)
      return (false);
    head = head->next;
  }
  return (true);
}
