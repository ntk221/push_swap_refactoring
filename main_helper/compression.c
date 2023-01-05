/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:48:24 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/04 03:50:58 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Usage : This function outputs string "Error\n" to stderr
//         and call exit() to finish the program.
// Note： exit() should be called after freed all allocated memory ...?


// Usage : This function converts char ** type data to int * type data
//          officially this function is used for convert argv to one array.
int		*argv_to_array(int argc, char **argv)
{
	int		*data;
	int		size;
	
	size = argc;
	data = (int *)ft_calloc(size, sizeof(int));
	for(int i = 1; i < size; i++)
		data[i - 1] = ft_atoi(argv[i]);
	return (data);
}

int	*bubble_sort_arr(int *list, int len)
{
	int		unsorted_until_index = len - 1;
	bool	sorted;
	int		tmp;
	int		i;

	sorted = false;
	while (!sorted)
	{
		i = 0;
		sorted = 1;
		while (i < unsorted_until_index)
		{
			if (list[i] > list[i + 1])
			{
				tmp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
		unsorted_until_index -= 1;
	}
	return (list);
}

int	linear_search(int *ordered_array, int search_value)
{
	int	i;

	i = 0;
	while (ordered_array)
	{
		if (ordered_array[i] == search_value)
			return (i);
		else if (ordered_array[i] > search_value)
			break ;
		i++;
	}
	return (-1);
}

// Usage : This function takes array of int and converts it to compressed one.
// Note : now, I assume data was created by malloc
int		*compression(int	*data, int argc)
{
	int	*copy;
	int	*res;
	int	size;

	size = argc - 1;
	copy = (int *)ft_calloc(size, sizeof(int));
	for(int i = 0; i < size; i++)
		copy[i] = data[i];
	copy = bubble_sort_arr(copy, size);
	res = (int *)ft_calloc(size, sizeof(int));
	for (int i = 0; i < size; i++)
		res[i] = linear_search(copy, data[i]);
	free(copy);
	free(data);
	return (res);
}

/*#include <stdio.h>
int main(int argc, char **argv)
{
	int *arr = argv_to_array(argc, argv);
	for(int i = 0; i < argc - 1; i++)
		printf("%d\n", arr[i]);

	int *res = compression(arr, argc);
	for (int i = 0; i < argc - 1; i++)
		printf("%d\n", res[i]);
}*/
