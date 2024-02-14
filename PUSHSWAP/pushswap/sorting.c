#include "push_swap.h"

static t_list	*find_annomaly(t_list **head)
{
	t_list	*tmp;
	int		prev_index;
	
	if (!*head)
		return (NULL);
	tmp = *head;
	while (tmp != NULL)
	{
		prev_index = tmp->i_value;
		tmp = tmp->next;
		if (tmp->i_value < prev_index)
			return (tmp);
	}
	return (head);
}

static void	innit_sorting_var(t_list **head_a, t_list **head_b, t_sort *s)
{
	list_indexer(head_a);
	list_indexer(head_b);
	s->stack_a_len = list_len(head_a);
	s->stack_b_len = list_len(head_b);
	assign_mid(head_a, head_b, s);
}

void	choose_action(t_list **head_a, t_list **head_b, t_sort *s)
{
	static short	arr[11] = {sa, sb, pa, pb, ra, rb, rra, rrb, ss, rr, rrr};

	innit_sorting_var(head_a, head_b, s);
	return ;
}