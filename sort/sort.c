#include "../includes/push_swap.h"

t_stack	*bubble_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		unsorted_until_index = stack_a->size - 1;
	bool	sorted = false;
	int		i;

	while (!sorted)
	{
		i = 0;
		sorted = true;
		while (i < unsorted_until_index)
		{
			print_stack(stack_a);
			print_stack(stack_b);
			if (i == unsorted_until_index - 1)
				stack_b = pb(stack_a, stack_b);
			else if (stack_a->head->value > stack_a->head->next->value)
			{
				stack_a = sa(stack_a);
				stack_a = ra(stack_a);
				sorted = false;
			}
			else
				stack_a = ra(stack_a);
			i++;
		}
		unsorted_until_index--;
	}
	return (stack_b);
}
