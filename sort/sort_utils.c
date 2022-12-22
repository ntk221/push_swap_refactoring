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
  t_stack_node  *itr;

  itr = stack_a->head;
  min = itr->value;
  while(itr->next != NULL)
  {
    if (min > itr->next->value)
      puts("hoge");//min = itr->next->value;
    itr++;
  }
  return (min);
}

int find_max_value(t_stack *stack_a)
{
  int           max;
  t_stack_node  *itr;

  itr = stack_a->head;
  max = itr->value;
  while(itr->next)
  {
    if (max < itr->next->value)
      max = itr->next->value;
    itr++;
  }
  return (max);
}
