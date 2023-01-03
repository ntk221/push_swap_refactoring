#include "../includes/push_swap.h"

#include <stdio.h>

t_stack_node *find_min_node(t_stack *stack_a, int *index)
{
  t_stack_node  *min;
  int           size;
  t_stack_node  *itr;
  size_t        id;

  itr = stack_a->head;
  min = itr;
  size = stack_a->size;
  id = 0;
  while(size)
  {
    if (min->value > itr->value)
    {
      min = itr;
      *index = id;
    }
    // printf("%d\n", min->value);
    itr = itr->next;
    size--;
    id++;
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

