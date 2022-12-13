#include "../includes/push_swap.h"
#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

void	test_create_stack(void)
{
	t_stack *stack = create_stack();
	printf("%p \n", stack);
	destroy_stack(stack);
}

void	test_push_front(void)
{
	t_stack *stack = create_stack();
	bool res = push_front(stack, 5);
	if(res)
		assert(stack->head->value == 5);
	res = push_front(stack, 10);
	if(res)
	{
		assert(stack->head->next->value == 5);
		assert(stack->head->value == 10);
	}
	assert(stack->last->value == 5);
	destroy_stack(stack);
}

void	test_push_back(void)
{
	t_stack *stack = create_stack();
	bool res = push_front(stack, 5);
	if(res)
		assert(stack->head->value == 5);
	res = push_back(stack, 10);
	if(res)
	{
		assert(stack->head->next->value == 10);
		assert(stack->head->value == 5);
	}
	destroy_stack(stack);
}

void	test_pop_stack(void)
{
	t_stack *stack = create_stack();
	push_front(stack, 5);
	push_front(stack, 10);
	int	*data = (int *)malloc(sizeof(int));
	bool ret = pop_stack(stack, &data);
	if (ret)
	{
		assert(*data == 10);
		printf("%d \n", *data);
	}
	free(data);
	destroy_stack(stack);
}

void	test_destroy_stack(void)
{
	t_stack	*stack = create_stack();
	push_front(stack, 5);
	destroy_stack(stack);
	puts("stack was successfuly destoyed");
}

void	test_swap(void)
{
	t_stack *a = create_stack();
	push_front(a, 5);
	push_front(a, 10);
	t_stack *res = swap(a);
	assert(res->head->value == 5);
	assert(res->head->next->value == 10);
	destroy_stack(a);
}

void	test_rotate(void)
{
	t_stack *stack = create_stack();
	push_front(stack, 5);
	push_front(stack, 10);
	push_front(stack, -10);
	t_stack *res = rotate(stack);
	assert(res->head->value == 10);
	assert(res->last->value == -10);
}

int main()
{
	test_create_stack();
	test_push_front();
	test_push_back();
	test_pop_stack();
	test_destroy_stack();
	test_swap();
	test_rotate();
}
