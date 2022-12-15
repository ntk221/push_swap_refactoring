#include "../includes/push_swap.h"

t_stack	*bubble_sort(t_stack *stack)
{
	int		unsorted_until_index = stack->size;
	bool	sorted = false;
	int		i;

	while (!sorted)
	{
		i = 1;
		sorted = true;
		while (i <= unsorted_until_index)
		{
			print_stack(stack);
			if (i == unsorted_until_index)
				stack = ra(stack);
			else if (stack->head->value > stack->head->next->value)
			{
				stack = sa(stack);
				stack = ra(stack);
				sorted = false;
			}
			else
				stack = ra(stack);
			i++;
		}
		unsorted_until_index--;
	}
	return (stack);
}
