#include "../includes/push_swap.h"

/*t_stack_node  *find_mid_index(t_stack *stack_a)
{
  t_stack_node  *target;
  t_stack_node  *last;
  int           min;
  int           max;

  target = stack_a->head;
  last = stack_a->last;
  while(target->next == NULL)
  {
    if ()
    {
      
    }
    target++;
  }
}*/

int find_min_value(t_stack *stack_a)
{
  int           min;
  t_stack_node  *itr;

  itr = stack_a->head;
  min = itr->value;
  while(itr->next == NULL)
  {
    if (min > itr->next->value)
      min = itr->next->value;
    itr++;
  }
  return (min);
}

