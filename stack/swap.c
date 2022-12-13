/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:35:43 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/13 08:47:08 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*swap(t_stack *stack)
{
	int		tmp;
	t_stack_node	*head;

	tmp = head->value;
	head->value = head->next->value;
	head->next->value = tmp;
	return (stack);
}