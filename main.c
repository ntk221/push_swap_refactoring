/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:53:51 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/17 13:38:43 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = create_stack();
	stack_b = create_stack();

	// TODO: stack_a の初期化

	// TODO: stack_a が ソートずみか否かで分岐
	// if (!is_sorted(stack_a))
	//    stack_a = sort(stack_a, stack_b);

	destroy_stack(stack_a);
	destroy_stack(stack_b);
}