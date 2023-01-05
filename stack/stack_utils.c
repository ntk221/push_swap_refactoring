/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:51:43 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/05 18:11:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void printb(unsigned int v) {
  unsigned int mask = (int)1 << (sizeof(v) * CHAR_BIT - 1);
  do putchar(mask & v ? '1' : '0');
  while (mask >>= 1);
}

void	print_stack(t_stack *stack)
{
	int	size;

	size = stack->size;
	puts("--------------------");
	while(size)
	{
		printb(stack->head->val);
		//printf("%d", stack->head->val);
		puts("");
		rotate(stack);
		size--;
	}
	puts("--------------------");
}

/*t_stack	*initialize_stack_a(t_stack *stack_a, int argc, char **argv)
{
	int		i;
	int		num;
	bool	res;
	bool	error;

	i = 1;
	stack_a = create_stack();
	while (i < argc)
	{
		error = true;
		num = ps_atoi(argv[i], &error);
		if (error)
			exit(1);
		res = push_back(stack_a, num);
		if (!res)
			exit(1);
		i++;
	}
	return (stack_a);
}*/

t_stack		*initialize_stack_a(t_stack *stack_a, int	*data, int argc)
{
	int		i;
	bool	res;

	i = 0;
	stack_a = create_stack();
	while (i < argc - 1)
	{
		res = push_back(stack_a, data[i]);
		if (!res)
			exit(1);
		i++;
	}
	return (stack_a);
}

bool	is_sorted(t_stack *stack)
{
	t_stack_node	*head;

	if (stack->head == NULL)
		return (true);
	head = stack->head;
	while (head->next != NULL)
	{
		if (head->val > head->next->val)
			return (false);
		head = head->next;
	}
	return (true);
}
