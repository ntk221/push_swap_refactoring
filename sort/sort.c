#include "../includes/push_swap.h"
#include <stdio.h>

t_stack	*bubble_sort(t_stack *stack, t_stack *stack_b)
{
	int		num_of_comparison = stack->size;
	int		i;

	while (num_of_comparison)
	{
		i = 0;
		while (i < num_of_comparison)
		{
			if (i == num_of_comparison - 1)
				stack_b = pb(stack, stack_b);
			else if (stack->head->value > stack->head->next->value)
			{
				stack = sa(stack);
				stack = ra(stack);
			}
			else
				stack = ra(stack);
			i++;
		}
		num_of_comparison--;
	}
	return (stack_b);
}

t_stack	*sort(t_stack *stack_a, t_stack *stack_b)
{
	stack_b = bubble_sort(stack_a, stack_b);
	return (stack_b);
}
