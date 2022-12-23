#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include<stddef.h>
#include<stdlib.h>
#include<stdbool.h>
#include <unistd.h>

typedef struct s_stack_node
{
	int				value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*head;
	t_stack_node	*last;
	size_t			size;
}	t_stack;

t_stack *create_stack(void);
bool	push_front(t_stack *stack, int value);
bool	push_back(t_stack *stack, int value);
bool	pop_front(t_stack *stack, int **data);
bool	pop_back(t_stack *stack, int **data);
void	destroy_stack(t_stack *stack);

void	print_stack(t_stack *stack);

t_stack	*swap(t_stack *stack);
t_stack *sa(t_stack *stack_a);
t_stack *sb(t_stack *stack_b);
t_stack	*rotate(t_stack *stack);
t_stack *ra(t_stack *stack_a);
t_stack *rb(t_stack *stack_b);
t_stack *reverse_rotate(t_stack *stack);
t_stack *rra(t_stack *stack_a);
t_stack *rrb(t_stack *stack_b);

t_stack	*push(t_stack *src, t_stack *dst);
t_stack *pa(t_stack *stack_a, t_stack *stack_b);
t_stack *pb(t_stack *stack_a, t_stack *stack_b);

t_stack *bubble_sort(t_stack *stack_a, t_stack *stack_b);
t_stack *sort_3(t_stack *stack_a);
t_stack *sort_5(t_stack *stack_a, t_stack *stack_b);
t_stack *sort(t_stack *stack_a, t_stack *stack_b);

t_stack_node  *find_min_node(t_stack *stack_a);
t_stack_node  *find_max_node(t_stack *stack_a);

static int	is_space(const char c);
static bool 	is_digits(const char c);
int		ft_atoi(const char *str, bool *error);
bool		check_argv(int argc, char **argv);
t_stack		*initialize_stack_a(t_stack *stack_a, int argc, char **argv);
bool		is_sorted(t_stack *stack);

#endif
