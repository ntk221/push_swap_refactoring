/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:35:43 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/14 03:18:17 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*swap(t_stack *stack)
{
	int		tmp;
	t_stack_node	*head;

	head = stack->head;
	if (stack->size < 2)
		return(NULL);
	tmp = head->val;
	head->val = head->next->val;
	head->next->val = tmp;
	return (stack);
}

t_stack	*sa(t_stack *stack_a)
{
	t_stack *result;

	result = swap(stack_a);
	if (!result)
		return (result);
	if (write(1, "sa\n", 3))
		return (result);
	else
		return (NULL);
}

t_stack *sb(t_stack *stack_b)
{
        t_stack *result;

        result = swap(stack_b);
        if (!result)
                return (result);
        if (write(1, "sb\n", 3))
                return (result);
        else
                return (NULL);
}
