#include "push_swap.h"

void	assign_mark(t_list **head)
{
	t_list		*tmp;
	const int	max = list_len(head);

	if (!*head)
		return ;
	tmp = *head;
	while (tmp != NULL)
	{
		if (tmp->i_value + 1 == max)
			tmp->mark = biggest;
		else
			tmp->mark = tmp->i_value + 1;
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

void	init_multiplier(t_list **head_a, t_sort *s)
{
	const double	len_a = list_len(head_a);
	const double	sort = sortedness_asc(head_a);

	s->act_pb_mult = 0.9;
	s->val_pb_mult = 1;

	s->act_pa_mult = 0.9;
	s->val_pa_mult = 1;
}
