/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:49:38 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/14 06:02:24 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

t_stack	*rotate(t_stack *stack)
{
	int		*data;
	bool	res;

	data = (int*)malloc(sizeof(int));
	res = pop_stack(stack, &data);
	printf("%d ", stack->head->next->value);
	if (!res)
		return (NULL);	
	res = push_back(stack, *data);
	printf("%d ", stack->head->next->value);
	free(data);
	if (!res)
		return (NULL);
	else
		return (stack);
}

t_stack *ra(t_stack *stack_a)
{
	t_stack	*result;

	result = rotate(stack_a);
	if (!result)
		return (result);
	if (write(1, "ra\n", 4))
		return (result);
}

t_stack *rb(t_stack *stack_b)
{
	t_stack *result;

	result = rotate(stack_b);
	if (!result)
		return (result);
	if (write(1, "rb\n", 4))
		return (result);
}

/*int main()
{
	t_stack *stack = create_stack();
	push_back(stack, 1);
	push_back(stack, 2);
	push_back(stack, 3);
	printf("%d \n", stack->head->value);
	rotate(stack);
	printf("%d \n", stack->head->value);
	printf("%d \n", stack->head->next->value);
	printf("%d \n", stack->head->next->next->value);
}*/
