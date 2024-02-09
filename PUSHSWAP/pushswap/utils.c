#include "push_swap.h"

void	wr_a(char *action)
{
	write(STDOUT_FILENO, action, ps_strlen(action));
	write(STDOUT_FILENO, "\n", 1);
	return ;
}