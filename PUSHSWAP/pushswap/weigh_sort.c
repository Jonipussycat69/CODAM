#include "push_swap.h"

void	init_act_arr(t_sort *s, int r_act, int rr_act)
{
	//LEFTOFF
}

// Chooses most efficient node globally
t_list	*ws_gl_path(t_list **head_a, t_list **head_b, t_sort *s)
{
	double	res;
	double	pb_weight;
	double	pa_weight;
	t_list	*pb_node;
	t_list	*pa_node;

	pb_node = ws_pb_path(head_a, head_b, s);
	pb_weight = s->act_weight;
	pa_node = ws_pa_path(head_a, head_b, s);
	pa_weight = s->act_weight;

	// Function for converting the weights so they can be compared

	res = pb_weight - pa_weight;
	if (res > 0)
		return (pb_node);
	else
		return (pa_node);
}

// Chooses most efficient node to push to b based on weight
// Size + amount of act, lower = better
t_list	*ws_pb_path(t_list **head_a, t_list **head_b, t_sort *s)
{
	int		i;
	int		r_act;
	int		rr_act;
	double	cur_weight;
	t_list	*the_node;

	i = 0;
	s->act_weight = 0.0;
	while (i < list_len(head_a))
	{
		s->act_node = n_li_node(head_a, i);
		cur_weight = weigh_pb(head_a, head_b, s);
		if (cur_weight < s->act_weight)
		{
			s->act_weight = cur_weight;
			the_node = s->act_node;
			r_act = s->r_actions;
			rr_act = s->rr_actions;
		}
		i++;
	}
	init_act_arr(s, r_act, rr_act);
	return (the_node);
}

// Chooses most efficient node to push to a based on weight
// Size - amount of act, higher = better
t_list	*ws_pa_path(t_list **head_a, t_list **head_b, t_sort *s)
{
	int		i;
	int		r_act;
	int		rr_act;
	double	cur_weight;
	t_list	*the_node;

	i = 0;
	s->act_weight = 0.0;
	while (i < list_len(head_b))
	{
		s->act_node = n_li_node(head_b, i);
		cur_weight = weigh_pa(head_a, head_b, s);
		if (cur_weight > s->act_weight)
		{
			s->act_weight = cur_weight;
			the_node = s->act_node;
			r_act = s->r_actions;
			rr_act = s->rr_actions;
		}
		i++;
	}
	init_act_arr(s, r_act, rr_act);
	return (the_node);
}

short	ws_pb_stage(t_list **head_a, t_list **head_b, t_sort *s)
{
	while (list_len(head_a) != WS_REMAIN)
	{
		update_variable_index(head_a, head_b);
		s->act_node = ws_pb_path(head_a, head_b, s);
		if (path_act(head_a, head_b, s) != ok)
			return (err);
	}
	return (ok);
}

short	ws_pa_stage(t_list **head_a, t_list **head_b, t_sort *s)
{
	return (ok);
}

short	weigh_sort(t_list **head_a, t_list **head_b, t_sort *s, \
	const short *arr)
{
	while (check_sort_asc(head_a) != ok || list_len(head_a) != s->total_inp)
	{
		if (ws_pb_stage(head_a, head_b, s) != ok)
			return (err);
		if (ws_pa_stage(head_a, head_b, s) != ok)
			return (err);
	}
	return (ok);
}
