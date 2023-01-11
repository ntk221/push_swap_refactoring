#include "../includes/push_swap.h"
#include <libft.h>
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
		assert(stack->head->val == 5);
	res = push_front(stack, 10);
	if(res)
	{
		assert(stack->head->next->val == 5);
		assert(stack->head->val == 10);
	}
	assert(stack->last->val == 5);
	destroy_stack(stack);
}

void	test_push_back(void)
{
	t_stack *stack = create_stack();
	bool res = push_front(stack, 5);
	if(res)
		assert(stack->head->val == 5);
	res = push_back(stack, 10);
	if(res)
	{
		assert(stack->head->next->val == 10);
		assert(stack->head->val == 5);
	}
	res = push_back(stack, -1000);
	assert(stack->head->next->next->val == -1000);
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
	printf("%d\n", stack->head->val);
	printf("%d\n", stack->head->next->val);
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
	assert(stack->head->val == 1);
	assert(stack->head->next->val == 2);
	assert(stack->last->val == 2);
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
	assert(res->head->val == 5);
	assert(res->head->next->val == 10);
	destroy_stack(stack);

	t_stack *stack_a = create_stack();
    push_front(stack_a, 5);
    push_front(stack_a, 5);
    push_front(stack_a, 10);
    res = sa(stack_a);
    assert(res->head->val == 5);
    assert(res->head->next->val == 10);
    destroy_stack(stack_a);

	t_stack *stack_b = create_stack();
    push_front(stack_b, 5);
    push_front(stack_b, 10);
    res = sb(stack_b);
    assert(res->head->val == 5);
    assert(res->head->next->val == 10);
    destroy_stack(stack_b);

}

void	test_rotate(void)
{
	t_stack *stack = create_stack();
	push_front(stack, 5);
	push_front(stack, 10);
	push_front(stack, -10);
	stack = rotate(stack);
	assert(stack->head->val == 10);
	assert(stack->head->next->val == 5);
	assert(stack->last->val == -10);
	assert(stack->last->prev->val == 5);
	assert(stack->last->prev->prev->val == 10);
	destroy_stack(stack);

	t_stack *stack_a = create_stack();
    push_front(stack_a, 5);
    push_front(stack_a, 10);
    push_front(stack_a, -10);
	// printf("%d\n", stack_a->head->next->next->val); // 5
    stack_a = ra(stack_a);
    assert(stack_a->head->val == 10);
	assert(stack_a->head->next->val == 5);
    assert(stack_a->last->val == -10);
	destroy_stack(stack_a);

	t_stack *stack_b = create_stack();
    push_front(stack_b, 5);
    push_front(stack_b, 10);
    push_front(stack_b, -10);
    stack_b = rb(stack_b);
    assert(stack_b->head->val == 10); 
    assert(stack_b->last->val == -10);
	destroy_stack(stack_b);
}

void	test_reverse_rotate(void)
{
	t_stack *stack = create_stack();
	push_back(stack, 1);
	push_back(stack, 2);
	push_back(stack, 3);
	stack = reverse_rotate(stack);
	// printf("%d \n", stack->head->val);
	assert(stack->head->val == 3);
	assert(stack->head->next->val == 1);
	assert(stack->last->val == 2);
	assert(stack->last->prev->val == 1);
	assert(stack->last->prev->prev->val == 3);
	destroy_stack(stack);

	t_stack *stack_a = create_stack();
	push_back(stack_a, 1);
	push_back(stack_a, 2);
	push_back(stack_a, 3);
	stack = rra(stack_a);
	// printf("%d \n", stack->head->val);
	assert(stack_a->head->val == 3);
	assert(stack_a->head->next->val == 1);
	assert(stack_a->last->val == 2);
	assert(stack_a->last->prev->val == 1);
	assert(stack_a->last->prev->prev->val == 3);
	destroy_stack(stack_a);
}

void	test_push(void)
{
	t_stack	*src = create_stack();
	push_back(src, 1);
	t_stack *dst = create_stack();
	push_back(dst, 2);
	dst = push(src, dst);
	assert(dst->head->val == 1);
	assert(dst->head->next->val == 2);
	assert(dst->last->val == 2);
	assert(src->size == 0);
	destroy_stack(src);
	destroy_stack(dst);

	t_stack *stack_a = create_stack();
	push_back(stack_a, 1);
	push_back(stack_a, 2);
	t_stack *stack_b = create_stack();
	push_back(stack_b, 3);
	push_back(stack_b, 4);
	printf("before pb a->size is ... %ld\n", stack_a->size);
	stack_b = pb(stack_a, stack_b);
	printf("after pb a->size is ... %ld\n" , stack_a->size);
	assert(1 == stack_b->head->val);	
	destroy_stack(src);
	destroy_stack(dst);

	stack_a = create_stack();
	push_back(stack_a, 1);
	push_back(stack_a, 2);
	stack_b = create_stack();
	push_back(stack_b, 3);
	push_back(stack_b, 4);
	printf("before pb b->size is ... %ld\n", stack_b->size);
	stack_a = pa(stack_a, stack_b);
	printf("after pb b->size is ... %ld\n" , stack_b->size);
}

void	test_print_stack(void)
{
	t_stack *stack = create_stack();
	push_back(stack, 1);
	push_back(stack, 2);
	push_back(stack, 3);
	print_stack(stack);
}

void  test_is_sorted(void)
{
  	t_stack *stack = create_stack();
  	push_back(stack, 1);
	  push_back(stack, 2);
  	push_back(stack, 3);
  	bool res = is_sorted(stack);
  	assert(res == true);
	push_back(stack, 2);
	res = is_sorted(stack);
	assert(res == false);
}

/*void  test_pb_selected_node(void)
{
  	t_stack *stack_a = create_stack();
    t_stack *stack_b = create_stack();
  	push_back(stack_a, 1);
	  push_back(stack_a, 2);
  	push_back(stack_a, 5);
  	push_back(stack_a, 3);
    push_back(stack_a, 6);
    t_stack_node *node = stack_a->head->next->next; //5
    assert(node->val == 5);
    stack_b = pb_selected_node(stack_a, stack_b, node);
}*/

int main(int argc, char **argv)
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
  	test_is_sorted();
  
  // test_pb_selected_node();
}
