/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:43:26 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/18 16:56:09 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <assert.h>

void	test_ft_atoi(void)
{
	bool error;

	error = true;
	int res = ft_atoi("10", &error);
	if (error)
	assert(res == 1);
}

void	test_initialize_stack_a(int argc, char **argv)
{
	// check_argv(argc, argv);
	t_stack	*stack_a;
	stack_a = initialize_stack_a(stack_a, argc, argv);
	print_stack(stack_a);
}

int main(int argc, char **argv)
{
	// test_ft_atoi();
	test_initialize_stack_a(argc, argv);
}
