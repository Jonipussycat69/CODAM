#include "push_swap.h"

short	check_sort(t_list **head)
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
			return (0);
	}
	return (1);
}

void	flagger(t_list **head, t_sort *s)
{
	// WHAT WILL THE FLAG INDICATE?
	return ;
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
