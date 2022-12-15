#include "../includes/push_swap.h"

t_stack	*bubble_sort(t_stack *stack)
{
	int		size = stack->size;
	bool	sorted = false;
	int		i;

	while (!sorted)
	{
		i = 0;
		sorted = true;
		while (i < size)
		{
			print_stack(stack);
			if (i == size - 1)
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
		size--;
	}
	return (stack);
}
