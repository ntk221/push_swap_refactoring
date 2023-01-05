/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 07:44:02 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/06 07:44:03 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Usage : This function outputs string "Error\n" to stderr
//         and call exit() to finish the program.
// Note： exit() should be called after freed all allocated memory ...?
void	error_message(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
