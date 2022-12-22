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

int find_min_value(t_stack *stack_a)
{
  int           min;
  int           size;
  t_stack_node  *itr;

  itr = stack_a->head;
  min = stack_a->head->value;
  size = stack_a->size;
  while(size)
  {
    if (min > itr->value)
      min = itr->value;
    itr = itr->next;
    size--;
  }
  return (min);
}

int find_max_value(t_stack *stack_a)
{
  int           max;
  int           size;
  t_stack_node  *itr;

  itr = stack_a->head;
  max = itr->value;
  size = stack_a->size;
  while(size)
  {
    if (max < itr->value)
      max = itr->value; // itr->next->value は だめ ...
    itr = itr->next;
    size--;
  }
  return (max);
}
