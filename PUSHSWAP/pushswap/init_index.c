#include "push_swap.h"

void	innit_sorting_var(t_list **head_a, t_list **head_b, t_sort *s)
{
	list_indexer(head_a);
	list_indexer(head_b);
}

// Updates si & li in the nodes
void	update_variable_index(t_list **head_a, t_list **head_b)
{
	list_indexer(head_a);
	stack_indexer(head_a);
	list_indexer(head_b);
	stack_indexer(head_b);
	return ;
}
