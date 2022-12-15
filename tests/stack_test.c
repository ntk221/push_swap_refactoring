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
	res = push_back(stack, -1000);
	assert(stack->head->next->next->value == -1000);
	destroy_stack(stack);
}

void	test_pop_front(void)
{
	t_stack *stack = create_stack();
	push_front(stack, 5);
	push_front(stack, 10);
	int	*data = (int *)malloc(sizeof(int));
	bool ret = pop_front(stack, &data);
	if (ret)
	{
		assert(*data == 10);
		printf("%d \n", *data);
	}
	free(data);
	push_back(stack, 100);
	push_back(stack, 1000);
	printf("%d\n", stack->head->value);
	printf("%d\n", stack->head->next->value);
	destroy_stack(stack);
}

void	test_pop_back(void)
{
	t_stack *stack = create_stack();
	push_back(stack, 1);
	push_back(stack, 2);
	push_back(stack, 3);
	int *data = (int *)malloc(sizeof(int));
	bool ret = pop_back(stack, &data);
	if (ret)
	{
		assert(*data == 3);
	}
	free(data);
	assert(stack->head->value == 1);
	assert(stack->head->next->value == 2);
	assert(stack->last->value == 2);
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
	t_stack *stack = create_stack();
	push_front(stack, 5);
	push_front(stack, 10);
	t_stack *res = swap(stack);
	assert(res->head->value == 5);
	assert(res->head->next->value == 10);
	destroy_stack(stack);

	t_stack *stack_a = create_stack();
    push_front(stack_a, 5);
    push_front(stack_a, 5);
    push_front(stack_a, 10);
    res = sa(stack_a);
    assert(res->head->value == 5);
    assert(res->head->next->value == 10);
    destroy_stack(stack_a);

	t_stack *stack_b = create_stack();
    push_front(stack_b, 5);
    push_front(stack_b, 10);
    res = sb(stack_b);
    assert(res->head->value == 5);
    assert(res->head->next->value == 10);
    destroy_stack(stack_b);

}

void	test_rotate(void)
{
	t_stack *stack = create_stack();
	push_front(stack, 5);
	push_front(stack, 10);
	push_front(stack, -10);
	stack = rotate(stack);
	assert(stack->head->value == 10);
	assert(stack->head->next->value == 5);
	assert(stack->last->value == -10);
	assert(stack->last->prev->value == 5);
	assert(stack->last->prev->prev->value == 10);
	destroy_stack(stack);

	t_stack *stack_a = create_stack();
    push_front(stack_a, 5);
    push_front(stack_a, 10);
    push_front(stack_a, -10);
	// printf("%d\n", stack_a->head->next->next->value); // 5
    stack_a = ra(stack_a);
    assert(stack_a->head->value == 10);
	assert(stack_a->head->next->value == 5);
    assert(stack_a->last->value == -10);
	destroy_stack(stack_a);

	t_stack *stack_b = create_stack();
    push_front(stack_b, 5);
    push_front(stack_b, 10);
    push_front(stack_b, -10);
    stack_b = rb(stack_b);
    assert(stack_b->head->value == 10); 
    assert(stack_b->last->value == -10);
	destroy_stack(stack_b);
}

void	test_reverse_rotate(void)
{
	t_stack *stack = create_stack();
	push_back(stack, 1);
	push_back(stack, 2);
	push_back(stack, 3);
	stack = reverse_rotate(stack);
	// printf("%d \n", stack->head->value);
	assert(stack->head->value == 3);
	assert(stack->head->next->value == 1);
	assert(stack->last->value == 2);
	assert(stack->last->prev->value == 1);
	assert(stack->last->prev->prev->value == 3);
	destroy_stack(stack);

	t_stack *stack_a = create_stack();
	push_back(stack_a, 1);
	push_back(stack_a, 2);
	push_back(stack_a, 3);
	stack = rra(stack_a);
	// printf("%d \n", stack->head->value);
	assert(stack_a->head->value == 3);
	assert(stack_a->head->next->value == 1);
	assert(stack_a->last->value == 2);
	assert(stack_a->last->prev->value == 1);
	assert(stack_a->last->prev->prev->value == 3);
	destroy_stack(stack_a);
}

void	test_push(void)
{
	t_stack	*src = create_stack();
	push_back(src, 1);
	t_stack *dst = create_stack();
	push_back(dst, 2);
	dst = push(src, dst);
	assert(dst->head->value == 1);
	assert(dst->head->next->value == 2);
	assert(dst->last->value == 2);
	assert(src->size == 0);
	destroy_stack(src);
	destroy_stack(dst);

	t_stack *stack_a = create_stack();
	push_back(stack_a, 1);
	push_back(stack_a, 2);
	t_stack *stack_b = create_stack();
	push_back(stack_b, 3);
	push_back(stack_b, 4);
	stack_b = pb(stack_a, stack_b);
	assert(1 == stack_b->head->value);	
}

void	test_print_stack(void)
{
	t_stack *stack = create_stack();
	push_back(stack, 1);
	push_back(stack, 2);
	push_back(stack, 3);
	print_stack(stack);
}
int main()
{
	test_create_stack();
	test_push_front();
	test_push_back();
	test_pop_front();
	test_pop_back();
	test_destroy_stack();
	test_swap();
	test_rotate();
	test_reverse_rotate();
	test_push();
	test_print_stack();
}
