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

#include <stdio.h>

t_stack_node *find_min_node(t_stack *stack_a)
{
  t_stack_node  *min;
  int           size;
  t_stack_node  *itr;

  itr = stack_a->head;
  min = itr;
  size = stack_a->size;
  while(size)
  {
    if (min->value > itr->value)
      min = itr;
    // printf("%d\n", min->value);
    itr = itr->next;
    size--;
  }
  return (min);
}

t_stack_node *find_max_node(t_stack *stack_a)
{
  t_stack_node  *max;
  int           size;
  t_stack_node  *itr;

  itr = stack_a->head;
  max = itr;
  size = stack_a->size;
  while(size)
  {
    if (max->value < itr->value)
      max = itr; // itr->next->value は だめ ...
    itr = itr->next;
    size--;
  }
  return (max);
}

