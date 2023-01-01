/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:35:12 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/18 16:57:17 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_space(const char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static bool is_digits(const char c)
{
    return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str, bool *error)
{
	int	sign;
	int	num;
	int	prev;

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
		prev = num;
		num = num * 10 + sign * (*str++ - '0');
		if (num > prev && sign == -1)
			return (0);
		if (num < prev && sign == 1)
			return (-1);
	}
	*error = false;
	return (num);
}

bool	check_argv(int argc, char **argv)
{
	int		i;
	bool	error;

	i = 1;
	while (i < argc)
	{
		error = true;
		ft_atoi(argv[i], &error);
		if (error)
			return (false);
		i++;
	}
	if (has_duplicate(argv))
		return (false);
	return (true);
}


#include <string.h>
#include <stdio.h>
bool	has_duplicate(char **src)
{
	size_t	i;
	size_t	j;

	i = 0;	
	while(src[i] != NULL)
	{
		j = i + 1;
		while(src[j] != NULL)
		{
			if (strcmp(src[i], src[j]) == 0)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}