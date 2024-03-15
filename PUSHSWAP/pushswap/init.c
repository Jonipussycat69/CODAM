#include "push_swap.h"

void	assign_mark(t_list **head)
{
	t_list	*tmp;

	if (!*head)
		return ;
	tmp = *head;
	while (tmp != NULL)
	{
		tmp->mark = tmp->i_value - 1;
		tmp = tmp->next;
	}
	return ;
}

void	assign_side(t_list **head)
{
	t_list	*tmp;
	double	middle;

	if (!*head)
		return ;
	tmp = *head;
	middle = (double)list_len(head) / 2.0;
	while (tmp != NULL)
	{
		if (tmp->list_index < middle)
			tmp->side = lower;
		if (tmp->list_index >= middle)
			tmp->side = upper;
		tmp = tmp->next;
	}
	return ;
}

void	init_sortedness(t_list **head_a, t_list **head_b, t_sort *s)
{
	s->sortedness_a = sortedness_asc(head_a);
	s->sortedness_b = sortedness_des(head_b);
}
