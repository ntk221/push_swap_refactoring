#include <stdio.h>
#include "../includes/push_swap.h"
/*typedef struct s_stack_node
{
        int                     value;
        struct s_stack_node     *next;
        struct s_stack_node     *prev;
}       t_stack_node;

typedef struct s_stack
{
        t_stack_node    *head;
        t_stack_node    *last;
        size_t          size;
}       t_stack;
*/


int main(void)
{
  t_stack *stack = create_stack();
  push_back(stack, 1);
  push_back(stack, 2);
  push_back(stack, 3);
  t_stack_node *itr = stack->head;
  int res = itr->next->value;
  itr = itr->next;
  res = itr->next->value;
    return 0;
}
