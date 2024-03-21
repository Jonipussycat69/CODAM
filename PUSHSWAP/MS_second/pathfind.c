#include "push_swap.h"

void	act_arr_reset(t_sort *s)
{
	short	i;

	i = 0;
	while (i < 8)
	{
		s->act_arr[i] = 0;
		i++;
	}
	return ;
}

// Finds initializes act_arr with bossible actions, returns total actions
void	path_init(t_list **head_a, t_list **head_b, t_sort *s, short stage)
{
	const int	act_r = s->act_node->list_index;
	const int	act_rrb = list_len(head_b) - act_r;
	const int	act_rra = list_len(head_a) - act_r;

	act_arr_reset(s);
	if (stage == s_pa)
	{
		s->act_arr[_rb] = act_r;
		s->act_arr[_rrb] = act_rrb;
		s->act_arr[_pa] = 1;
		s->rr_actions = act_rrb;
	}
	if (stage == s_pb)
	{
		s->act_arr[_ra] = act_r;
		s->act_arr[_rra] = act_rra;
		s->act_arr[_pb] = 1;
		s->rr_actions = act_rra;
	}
	s->r_actions = act_r;
	return ;
}

double	path_weigh(t_list **head_a, t_list **head_b, t_sort *s, short stage)
{
	const double	value = get_i_value(s->act_node) + 1.0;
	double			sortedness;
	double			act;
	double			act_weight;

	path_init(head_a, head_b, s, stage);
	sortedness = precalc(head_a, head_b, s, stage);
	if (s->r_actions == 0)
		act = s->rr_actions + 1.0;
	else
		act = s->r_actions + 1.0;
	if (stage == s_pb)
	{
		act_weight = (value * s->val_pb_mult) + ((act * s->act_pb_mult) / 2);
		return (act_weight * ((1.0 / (1 + ((sortedness / 10000.0)) * s->sort_mult))));
	}
	else
	{
		act_weight = s->total_inp + ((value * s->val_pa_mult) - \
		((act * s->act_pa_mult) / 2));
		return (act_weight * (1 + ((sortedness / 10000.0)) * s->sort_mult));
	}
}
