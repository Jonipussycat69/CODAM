#include "push_swap.h"

// Parses t_act and inputs it into do_actions
short	path_act(t_list **head_a, t_list **head_b, t_act *a)
{
	return (ok);
}

// Chooses most efficient node to push to b based on weight
// Size - amount of act, higher = better
t_list	*ws_pb_path(t_list **head_a, t_list **head_b, t_sort *s, t_act *a)
{
	int		i;
	double	highest_weihgt;
	double	cur_weight;
	t_list	*the_node;

	i = 0;
	highest_weihgt = 0;
	while (i < list_len(head_a))
	{
		a->node_a = n_li_node(head_a, i);
		cur_weight = weigh_pb(head_a, head_b, s, a);
		if (cur_weight > highest_weihgt)
		{
			highest_weihgt = cur_weight;
			the_node = a->node_a;
		}
		i++;
	}
	return (the_node);
}

// Chooses most efficient node to push to a based on weight
// Size + amount of act, lower = better
t_list	*ws_pa_path(t_list **head_a, t_list **head_b, t_sort *s, t_act *a)
{
	return (ok);
}

// Initializes type and amount of actions in t_act
// Weighs node_b for pb stage
// Size - amount of act, higher = better
// Include sortednes of stack a and b into the equation!!
// Include multipliers into the equation!!
double	weigh_pb(t_list **head_a, t_list **head_b, t_sort *s, t_act *a)
{
	const int	act_ra = a->node_a->list_index;
	const int	act_rra = list_len(head_a) - a->node_a->list_index;
	return (ok);
}

// Initializes type and amount of actions in t_act
// Weighs node_a for pa stage
// Size + amount of act, lower = better
// Include sortednes of stack a and b into the equation!!
// Include multipliers into the equation!!
double	weigh_pa(t_list **head_a, t_list **head_b, t_sort *s, t_act *a)
{
	return (ok);
}

short	ws_pb_stage(t_list **head_a, t_list **head_b, t_sort *s, t_act *a)
{
	while (list_len(head_a) != WS_REMAIN)
	{
		update_variable_index(head_a, head_b);
		a->node_a = ws_pb_path(head_a, head_b, s, a);
		weigh_pb(head_a, head_b, s, a);
		if (path_act(head_a, head_b, a) != ok)
			return (err);
	}
	return (ok);
}

short	ws_pa_stage(t_list **head_a, t_list **head_b, t_sort *s, t_act *a)
{
	return (ok);
}

short	weigh_sort(t_list **head_a, t_list **head_b, t_sort *s, \
	const short *arr)
{
	t_act	a;

	while (check_sort_asc(head_a) != ok || list_len(head_a) != s->total_inp)
	{
		if (ws_pb_stage(head_a, head_b, s, &a) != ok)
			return (err);
		if (ws_pa_stage(head_a, head_b, s, &a) != ok)
			return (err);
	}
	return (ok);
}
