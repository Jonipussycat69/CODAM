#include "push_swap.h"

// Finds path with best sortedness - pb
int	pathfind_pb(t_list **head_a, t_list **head_b, t_sort *s)
{
	const int	act_ra = s->act_node->list_index;
	const int	act_rra = list_len(head_a) - act_ra;
	int			total_act;

	// LEFTOFF!
	return (total_act);
}

// Finds path with best sortedness - pa
int	pathfind_pa(t_list **head_a, t_list **head_b, t_sort *s)
{
	const int	act_rb = s->act_node->list_index;
	const int	act_rrb = list_len(head_b) - act_rb;
	int			total_act;

	// LEFTOFF!
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
	const double	act = pathfind(head_a, head_b, s);
	const double	value = get_i_value(s->act_node);

	init_multiplier(head_a, head_b, s, stage);
	if (stage == s_pb)
		return ((value * s->val_mult) + (act * s->act_mult));
	else
		return ((value * s->val_mult) - (act * s->act_mult));
}
