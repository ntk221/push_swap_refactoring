/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:53:51 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/18 17:06:49 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	bool	*error;

	if (argc < 2)
		exit(1);
	if (!(check_argv(argc, argv)))
		exit(1);
	error = true;
	stack_a = initialize_stack_a(stack_a, &error);

	// TODO: stack_a が ソートずみか否かで分岐
	// if (!is_sorted(stack_a))
	//    stack_a = sort(stack_a, stack_b);

}

