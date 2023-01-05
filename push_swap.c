/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:53:51 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/05 16:57:45 by codespace        ###   ########.fr       */
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
		exit(1);
	if (!(check_argv(argc, argv)))
	{
		fprintf(stderr, "Error\n");
		exit(1);
	}
	data = argv_to_array(argc, argv);
	data = compression(data, argc);
	// for (int i = 0; i < argc - 1; i++)
	//	printf("%d\n",data[i]);
	// free(data);
	stack_a = initialize_stack_a(stack_a, data, argc);
	free(data);
	// print_stack(stack_a);
	stack_b = create_stack();
	if (!is_sorted(stack_a))
		stack_a = sort(stack_a, stack_b);
	print_stack(stack_a);
	destroy_stack(stack_a);
	destroy_stack(stack_b);
}
