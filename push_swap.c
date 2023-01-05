/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:53:51 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/06 08:15:32 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*data;
	bool	error;

	if (argc < 2)
		error_message();
	if (!(check_argv(argc, argv)))
		error_message();
	data = argv_to_array(argc, argv);
	data = compression(data, argc);
	stack_a = initialize_stack_a(stack_a, data, argc);
	free(data);
	stack_b = create_stack();
	if (!is_sorted(stack_a))
		stack_a = sort(stack_a, stack_b);
	destroy_stack(stack_a);
	destroy_stack(stack_b);
}
