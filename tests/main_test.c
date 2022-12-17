/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:39:46 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/17 14:18:22 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    if (!check_argv(argc, argv))
        puts("Error!");
    else
        puts("OK");
}