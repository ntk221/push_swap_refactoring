#include "../includes/push_swap.h"

int main(void)
{
  t_stack *stack = create_stack();
  push_back(stack, 1);
  t_stack_node *node = stack->head;

  int res = node->value;

  return 0;
}
