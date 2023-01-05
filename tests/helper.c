/* 
    目的: char 型のポインタを受け取って，ポインタの先に格納されているメモリ領域について，それらを区切り文字が出現するたびに区切って，stack に格納し， return する
*/
#include <assert.h>
#include "../includes/push_swap.h"
#include <stdio.h>

t_stack *array_to_stack(char *arr, char delim)
{
    int     val;
    t_stack *stack = create_stack();
    while(*arr != '\0')
    {
        if(*arr == delim)
        {
            arr++;
            continue;
        }
        val = *arr - '0';
        bool res = push_back(stack, val);
        if (!res)
            return NULL;
        arr++;
    }
    return stack;
}

void printb(unsigned int v) {
  unsigned int mask = (int)1 << (sizeof(v) * CHAR_BIT - 1);
  do putchar(mask & v ? '1' : '0');
  while (mask >>= 1);
}

void	print_stack(t_stack *stack)
{
	int	size;

	size = stack->size;
	puts("--------------------");
	while(size)
	{
		printb(stack->head->val);
		//printf("%d", stack->head->val);
		puts("");
		rotate(stack);
		size--;
	}
	puts("--------------------");
}

#include <stdio.h>

void    test_array_to_stack(void)
{
    char        *src1  = "1 2 3 4 5";
    t_stack     *stack = array_to_stack(src1, ' '); 
    // printf("%d\n", stack->head->val);
    assert(stack->head->val == 1);
    assert(stack->head->next->val == 2);
    assert(stack->head->next->next->val == 3);
    assert(stack->head->next->next->next->next->val == 5);
}

/*int main(void)
{
    test_array_to_stack();
    return 0;
}*/
