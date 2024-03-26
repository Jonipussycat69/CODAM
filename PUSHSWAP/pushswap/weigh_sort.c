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

void	ws_pb_stage(t_list **head_a, t_list **head_b, t_sort *s)
{
	while (list_len(head_a) != 3 && strict_check_asc(head_a) != ok)
	{
		update_variable_index(head_a, head_b);
		ws_pb_path(head_a, head_b, s);
		do_act_arr(head_a, head_b, s);
		// print_values(head_a, 'a');// TEST!
		// print_values(head_b, 'b');// TEST!
	}
	return ;
}

// void	ws_pb_stage(t_list **head_a, t_list **head_b, t_sort *s)
// {
// 	while (list_len(head_a) != 3)
// 	{
// 		update_variable_index(head_a, head_b);
// 		ws_pb_path(head_a, head_b, s);
// 		do_act_arr(head_a, head_b, s);
// 		// print_values(head_a, 'a');// TEST!
// 		// print_values(head_b, 'b');// TEST!
// 	}
// 	return ;
// }

void	ws_pa_stage(t_list **head_a, t_list **head_b, t_sort *s)
{
	while (list_len(head_b) != 0)
	{
		update_variable_index(head_a, head_b);
		ws_pa_path(head_a, head_b, s);
		do_act_arr(head_a, head_b, s);
		// print_values(head_a, 'a');// TEST!
		// print_values(head_b, 'b');// TEST!
	}
	return ;
}
