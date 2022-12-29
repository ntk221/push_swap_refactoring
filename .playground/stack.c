#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct s_stack_node
{
        int                     value;
        struct s_stack_node     *next;
}       t_stack_node;

typedef struct s_stack
{
        t_stack_node    *head;
        size_t          size;
}       t_stack;


t_stack *create_stack(void)
{
	t_stack *stack;

	stack = (t_stack*)malloc(sizeof(t_stack));
	if (stack == NULL)
		exit(1);
	stack->head = NULL;
	stack->size = 0;
	return (stack);
}

bool	push_front(t_stack *stack,int value)
{
	t_stack_node	*node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (node == NULL)
		return(false);
	node->value = value;
	node->next = stack->head;
	stack->head = node; //新しく追加した node を head として更新する
	stack->size++;
	return (true);
}

int main(void)
{
  t_stack *stack = create_stack();
  push_front(stack, 1);
  push_front(stack, 2);
  push_front(stack, 3);
  t_stack_node *itr = stack->head;
}
