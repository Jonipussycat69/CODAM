#include "push_swap.h"

int	get_mid_si(t_list **head, t_sort *s)
{
	t_list	*tmp;
	int		mid;
	
	mid = list_len(head);
	stack_indexer(head);
	if (!*head || mid < 3)
		return (mid);
	if (mid % 2 == 0)
		return ((mid / 2) - 1);
	return ((mid - 1) / 2);
}

void	assign_mid(t_list **head_a, t_list **head_b, t_sort *s)
{
	t_list	*tmp;

	s->mid_si_a = get_mid_si(head_a, s);
	tmp = n_si_node(head_a, s->mid_si_a);
	s->mid_li_a = tmp->list_index;
	s->mid_iv_a = tmp->i_value;
	s->mid_si_b = get_mid_si(head_b, s);
	tmp = n_si_node(head_b, s->mid_si_b);
	s->mid_li_b = tmp->list_index;
	s->mid_iv_b = tmp->i_value;
	return ;
}
