#include "push_swap.h"

void	init_act_arr(t_sort *s, int r_act, int rr_act, short stage)
{
	if (stage == s_pb)
	{
		s->act_arr[_ra] = r_act;
		s->act_arr[_rra] = rr_act;
	}
	else
	{
		s->act_arr[_rb] = r_act;
		s->act_arr[_rrb] = rr_act;
	}
}

// Chooses most efficient node to push to b based on weight
// Size + amount of act * 1/sortedness, lower = better
t_list	*ws_pb_path(t_list **head_a, t_list **head_b, t_sort *s)
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
		cur_weight = path_weigh(head_a, head_b, s, s_pb);
		// printf("%s>> weight pb %d[%d] = %f%s\n", DIMMED_F, s->act_node->i_value, i, cur_weight, RESET_F);// TEST!
		if (cur_weight < s->act_weight || i == 0)
		{
			s->act_weight = cur_weight;
			the_node = s->act_node;
			r_act = s->r_actions;
			rr_act = s->rr_actions;
		}
		i++;
	}
	init_act_arr(s, r_act, rr_act, s_pb);
	return (the_node);
}

// Chooses most efficient node to push to a based on weight
// Size - amount of act * sortedness, higher = better
t_list	*ws_pa_path(t_list **head_a, t_list **head_b, t_sort *s)
{
	int		i;
	int		r_act;
	int		rr_act;
	double	cur_weight;
	t_list	*the_node;

	i = 0;
	s->act_weight = 0;
	while (i < list_len(head_b))
	{
		s->act_node = n_li_node(head_b, i);
		cur_weight = path_weigh(head_a, head_b, s, s_pa);
		// printf("%s>> weight pa %d[%d] = %f%s\n", DIMMED_F, s->act_node->i_value, i, cur_weight, RESET_F);// TEST!
		if (cur_weight > s->act_weight || i == 0)
		{
			s->act_weight = cur_weight;
			the_node = s->act_node;
			r_act = s->r_actions;
			rr_act = s->rr_actions;
		}
		i++;
	}
	init_act_arr(s, r_act, rr_act, s_pa);
	return (the_node);
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

short	ws_pb_stage(t_list **head_a, t_list **head_b, t_sort *s)
{
	while (list_len(head_a) != WS_REMAIN && strict_check_asc(head_a) != ok)
	{
		update_variable_index(head_a, head_b);
		ws_pb_path(head_a, head_b, s);
		do_act_arr(head_a, head_b, s);
		// print_values(head_a, 'a');// TEST!
		// print_values(head_b, 'b');// TEST!
	}
	return (ok);
}

short	ws_pa_stage(t_list **head_a, t_list **head_b, t_sort *s)
{
	while (list_len(head_b) != 0)
	{
		update_variable_index(head_a, head_b);
		ws_pa_path(head_a, head_b, s);
		do_act_arr(head_a, head_b, s);
		// print_values(head_a, 'a');// TEST!
		// print_values(head_b, 'b');// TEST!
	}
	return (ok);
}

void	weigh_sort(t_list **head_a, t_list **head_b, t_sort *s)
{
	init_multiplier(head_a, head_b, s, 0);
	ws_pb_stage(head_a, head_b, s);
	// print_values(head_a, 'a');// TEST!
	// print_values(head_b, 'b');// TEST!
	return ;
}

// void	weigh_sort(t_list **head_a, t_list **head_b, t_sort *s)
// {
// 	int	round;

// 	round = 0;
// 	while (check_sort_asc(head_a) != ok || list_len(head_a) != s->total_inp)
// 	{
// 		init_multiplier(head_a, head_b, s, round);
// 		if (s->total_inp > 3)
// 			ws_pb_stage(head_a, head_b, s);
// 		hardsort(head_a, head_b, st_a);
// 		ws_pa_stage(head_a, head_b, s);
// 		round++;
// 		print_values(head_a, 'a');// TEST!
// 		print_values(head_b, 'b');// TEST!
// 	}
// 	return ;
// }
