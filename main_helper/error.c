#include "../includes/push_swap.h"

// Usage : This function outputs string "Error\n" to stderr
//         and call exit() to finish the program.
// Note： exit() should be called after freed all allocated memory ...?
void	error_message(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
