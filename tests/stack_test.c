#include "../includes/push_swap.h"
#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

void	test_create_stack(void)
{
	t_stack *stack_ptr = create_stack();
	printf("%p ", stack_ptr);
}

void	test_push_stack(void)
{
	t_stack *stack_ptr = create_stack();
	push_stack(stack_ptr, 5);
	assert(stack_ptr->head->value == 5);
	push_stack(stack_ptr, 10);
	assert(stack_ptr->head->prev->value == 5);
	assert(stack_ptr->head->value == 10);
}

void	test_pop_stack(void)
{
	t_stack *stack_ptr = create_stack();
	push_stack(stack_ptr, 5);
	push_stack(stack_ptr, 10);
	int	*data = (int *)malloc(sizeof(int));
	bool ret = pop_stack(stack_ptr, &data);
	if (ret)
	{
		assert(*data == 10);
		printf("%d ", *data);
	}
}

int main()
{
	test_create_stack();
	test_push_stack();
	test_pop_stack();
}
