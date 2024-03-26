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

void	init_multiplier(t_sort *s)
{
	const double	inp_size = s->total_inp;

	s->act_pb_mult = 0.9;
	if (s->total_inp > 450)
		s->act_pb_mult = 0.9 - (inp_size / 10000);
	s->val_pb_mult = 1;
	if (s->total_inp < 10 && s->total_inp > 3)
		s->val_pb_mult = 1 - (2 / inp_size);
}
