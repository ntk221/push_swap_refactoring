/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:39:46 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/18 16:29:55 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_stack *stack_a;

    if (!check_argv(argc, argv))
        puts("Error!");
    else
        stack_a = initialize_stack_a(stack_a, argc, argv);
    // print_stack(stack_a);
    // destroy_stack(stack_a);
    // destroy_stack(stack_b);
    return (0);
}