#include "push_swap.h"

void	algo_sub(t_list **head_a, t_list **head_b, t_sort *s, short *arr)
{
	innit_sorting_var(head_a, head_b, s);
	flagger(head_a, s);
	flagger(head_b, s);
	return ;
}
