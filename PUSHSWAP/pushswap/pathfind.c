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
int	path_init(t_list **head_a, t_list **head_b, t_sort *s, short stage)
{
	const int	act_r = s->act_node->list_index;
	const int	act_rrb = list_len(head_b) - act_r;
	const int	act_rra = list_len(head_a) - act_r;
	int			total_act;

	act_arr_reset(s);
	if (stage == s_pb)
	{
		s->act_arr[_rb] = act_r;
		s->act_arr[_rrb] = act_rrb;
		s->act_arr[_pa] = 1;
	}
	if (stage == s_pa)
	{
		s->act_arr[_ra] = act_r;
		s->act_arr[_rra] = act_rra;
		s->act_arr[_pb] = 1;
	}
	total_act = path_combi(head_a, head_b, s);
	return (total_act);
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
	const double	act = path_init(head_a, head_b, s, stage);
	const double	value = get_i_value(s->act_node);

	init_multiplier(head_a, head_b, s, stage);
	if (stage == s_pb)
		return ((value * s->val_mult) + (act * s->act_mult));
	else
		return ((value * s->val_mult) - (act * s->act_mult));
}
