#include "push_swap.h"

void	assign_large(t_list **head_a, t_list **head_b, t_sort *s)
{
	s->large_si_a = list_len(head_a) - 1;
	return ; // USEFUL??
}

void	innit_sorting_var(t_list **head_a, t_list **head_b, t_sort *s)
{
	list_indexer(head_a);
	list_indexer(head_b);
	s->stack_a_len = list_len(head_a);
	s->stack_b_len = list_len(head_b);
	assign_mid(head_a, head_b, s);
	assign_large(head_a, head_b, s);
}
