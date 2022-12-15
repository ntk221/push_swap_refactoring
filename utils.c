/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:35:12 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/14 09:38:45 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	is_space(const char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static bool is_digits(const char c)
{
    return (c >= 0 && c <= 9);
}

int	ft_atoi(const char *str)
{
	int				sign;
	long long int	num;
	long long int	n;

	sign = 1;
	num = 0;
	while (*str != '\0' && is_space(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
    if (!is_digits(*str))
        exit(1);
	while (*str >= '0' && *str <= '9')
	{
		n = num;
		num = num * 10 + sign * (*str++ - '0');
		if (num > n && sign == -1)
			return (0);
		if (num < n && sign == 1)
			return (-1);
	}
	return (num);
}