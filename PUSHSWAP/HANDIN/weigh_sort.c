#include "push_swap.h"

// Finds initializes act_arr with bossible actions, returns total actions
static void	ws_path_init(t_list **head_a, t_list **head_b, t_sort *s)
{
	const int	act_r = s->act_node->list_index;
	const int	act_rra = list_len(head_a) - act_r;

	act_arr_reset(s);
	s->act_arr[_ra] = act_r;
	s->act_arr[_rra] = act_rra;
	s->act_arr[_pb] = 1;
	s->rr_actions = act_rra;
	s->r_actions = act_r;
	return ;
}

static double	ws_path_weigh(t_list **head_a, t_list **head_b, t_sort *s)
{
	const double	value = get_i_value(s->act_node) + 1.0;
	double			act;

	ws_path_init(head_a, head_b, s);
	if (s->r_actions > s->rr_actions)
	{
		s->r_actions = 0;
		act = s->rr_actions + 1.0;
	}
	else
	{
		s->rr_actions = 0;
		act = s->r_actions + 1.0;
	}
	return ((value * s->val_pb_mult) + (act * s->act_pb_mult));
}

// Chooses most efficient node to push to b based on weight
// Size + amount of act * 1/sortedness, lower = better
static void	ws_pb_path(t_list **head_a, t_list **head_b, t_sort *s)
{
	int		i;
	int		r_act;
	int		rr_act;
	double	cur_weight;
	t_list	*the_node;

	i = 0;
	s->act_weight = 0;
	while (i < list_len(head_a))
	{
		s->act_node = n_li_node(head_a, i);
		cur_weight = ws_path_weigh(head_a, head_b, s);
		if (cur_weight < s->act_weight || i == 0)
		{
			s->act_weight = cur_weight;
			the_node = s->act_node;
			r_act = s->r_actions;
			rr_act = s->rr_actions;
		}
		i++;
	}
	s->act_arr[_ra] = r_act;
	s->act_arr[_rra] = rr_act;
	return ;
}

void	weigh_sort_pb(t_list **head_a, t_list **head_b, t_sort *s)
{
	while (list_len(head_a) != 3 && strict_check_asc(head_a) != ok)
	{
		update_variable_index(head_a, head_b);
		ws_pb_path(head_a, head_b, s);
		do_act_arr(head_a, head_b, s);
	}
	return ;
}
