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
	int			total_act;

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

// Finds best path to get the act_node above the mark - pb stage
int	pathmark_pb(t_list **head_a, t_list **head_b, t_sort *s)
{
	const int	act_ra = s->act_node->list_index;
	const int	act_rra = list_len(head_a) - act_ra;
	const int	act_rb = get_li(n_iv_node(head_b, s->act_node->mark));
	const int	act_rrb = list_len(head_b) - act_rb;
	int			total_act;

	if (act_rb == err)
		return (err);
	
	return (total_act);
}

// Finds best path to get the act_node above the mark - pa stage
int	pathmark_pa(t_list **head_a, t_list **head_b, t_sort *s)
{
	const int	act_rb = s->act_node->list_index;
	const int	act_rrb = list_len(head_b) - act_rb;
	const int	act_ra = get_li(n_iv_node(head_a, s->act_node->mark));
	const int	act_rra = list_len(head_a) - act_ra;
	int			total_act;

	if (act_rb == err)
		return (err);
	
	return (total_act);
}

double	path_weigh(t_list **head_a, t_list **head_b, t_sort *s, short stage)
{
	const double	value = get_i_value(s->act_node);
	double			sortedness;
	double			act;
	double			act_weight;

	path_init(head_a, head_b, s, stage);
	init_multiplier(head_a, head_b, s, stage);
	sortedness = precalc(head_a, head_b, s, stage);
	if (s->r_actions == 0)
		act = s->rr_actions + 1;
	else
		act = s->r_actions + 1;
	if (stage == s_pb)
	{
		act_weight = (value * s->val_mult) + (act * s->act_mult);
		return (act_weight * ((1.0 / (sortedness / 100.0)) * s->sort_mult));
	}
	else
	{
		act_weight = (value * s->val_mult) - (act * s->act_mult);
		return (act_weight * ((sortedness / 100.0) * s->sort_mult));
	}
}
