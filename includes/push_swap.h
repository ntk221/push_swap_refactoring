#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include<stddef.h>
#include<stdlib.h>

typedef struct s_stack_node
{
	int				value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*head;
	size_t			size;
}	t_stack;

t_stack *create_stack(void);
void	push_stack(t_stack *stack_ptr, int value);
int	pop_stack(t_stack *stack_ptr);

#endif
