#include "../includes/push_swap.h"
#include <stdio.h>

t_stack	*bubble_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		num_of_comparison = stack_a->size;
	int		i;

	while (num_of_comparison)
	{
		i = 0;
		while (i < num_of_comparison)
		{
			if (i == num_of_comparison - 1)
				stack_b = pb(stack_a, stack_b);
			else if (stack_a->head->value > stack_a->head->next->value)
			{
				stack_a = sa(stack_a);
				stack_a = ra(stack_a);
			}
			else
				stack_a = ra(stack_a);
			i++;
		}
		num_of_comparison--;
	}
  i = 0;
  while(stack_b->size)
    stack_a = pa(stack_a, stack_b);
	return (stack_a);
}

t_stack *sort(t_stack *stack_a, t_stack *stack_b)
{
	stack_a = bubble_sort(stack_a, stack_b);
	return (stack_a);
}
