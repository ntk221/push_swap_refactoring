#include "../includes/push_swap.h"

static void	rank_simplification(t_stack *a)
{
	t_stack	*tmp;
	int	i;

	tmp = NULL;
	i = 0;
	while(i < a->size)
	{
		tmp = find_min_list(a);
		tmp->rank = i
	}
}
