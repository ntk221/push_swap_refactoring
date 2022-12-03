#include "../includes/push_swap.h"

t_stack *create_stack(void)
{
	t_stack *stack_ptr;

	stack_ptr = (t_stack*)malloc(sizeof(t_stack));
	if (stack_ptr == NULL)
		exit(1);
	stack_ptr->head = NULL;
	stack_ptr->size = 0;
	return (stack_ptr);
}
