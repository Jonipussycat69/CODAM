#include "push_swap.h"

// Parses t_ws and inputs it into do_actions
short	path_act(t_list **head_a, t_list **head_b, t_sort *s)
{
	return (ok);
}

int	pathfind(t_list **head_a, t_list **head_b, t_sort *s)
{
	const int	act_ra = s->act_node->list_index;
	const int	act_rra = list_len(head_a) - s->act_node->list_index;
	int			total_act;

	// LEFTOFF!
	return (total_act);
}

double	path_weigh(t_list **head_a, t_list **head_b, t_sort *s, short stage)
{
	const double	act = pathfind(head_a, head_b, s);
	const double	value = get_i_value(s->act_node);

	init_multiplier(head_a, head_b, s, stage);
	if (stage == s_pb)
		return ((value * s->val_mult) + (act * s->act_mult));
	else
		return ((value * s->val_mult) - (act * s->act_mult));
}
