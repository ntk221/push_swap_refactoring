/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:35:12 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/06 07:55:03 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_space(const char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	atoi_loop(const char *str, int num, int sign)
{
	int	prev;

	while (*str >= '0' && *str <= '9')
	{
		prev = num;
		num = num * 10 + sign * (*str - '0');
		if (num > prev && sign == -1)
			return (0);
		if (num < prev && sign == 1)
			return (-1);
		str++;
	}
	return (num);
}

int	ps_atoi(const char *str, bool *error)
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
	if (!((*str >= '0' && *str <= '9')))
		error_message();
	num = atoi_loop(str, num, sign);
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
		ps_atoi(argv[i], &error);
		if (error)
			error_message();
		i++;
	}
	if (has_duplicate(argv))
		return (false);
	return (true);
}

bool	has_duplicate(char **src)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i] != NULL)
	{
		j = i + 1;
		while (src[j] != NULL)
		{
			if (ft_strncmp(src[i], src[j], ft_strlen(src[i])) == 0)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}
