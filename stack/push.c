/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:38:44 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/15 11:13:20 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

t_stack *push(t_stack *src, t_stack *dst)
{
	int		*data;
	bool	ret;

	if (!(src->size > 0))
		return (NULL);
	data = (int *)malloc(sizeof(int));
	if (!data)
		return (NULL);
	ret = pop_front(src, &data);
	if (!ret)
	{
		free(data);
		return (NULL);
	}
	ret = push_front(dst, *data);
	if (!ret)
	{
		free(data);
		return (NULL);
	}
	free(data);
	return (dst);
}