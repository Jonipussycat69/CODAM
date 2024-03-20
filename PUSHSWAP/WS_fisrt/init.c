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
	s->global_sorted = sortedness_gl(head_a, head_b, s, global);
}

void	init_multiplier(t_list **head_a, t_list **head_b, t_sort *s, int round)
{
	const double	len_a = list_len(head_a);
	const double	len_b = list_len(head_b);
	double			val_mult_round;

	s->act_pb_mult = 1.0;//? [act_mul = (len_ / total_len) * sort_] ?
	s->act_pa_mult = 1.0;//? [act_mul = (len_ / total_len) * sort_] ?

	val_mult_round = 1.0;
	while (round-- > 0)
		val_mult_round = val_mult_round * 1.01;
	s->val_pb_mult = 2.0 * val_mult_round;
	s->val_pa_mult = 2.0 * val_mult_round;

	s->sort_mult = 0.0;// HIGHER = SLOWER!??
	s->receive_mult = 0.0;
}
