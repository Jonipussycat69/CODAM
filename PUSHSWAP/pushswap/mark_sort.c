#include "push_swap.h"

static double	pathmark_big(t_list **head_a, t_list **head_b, t_sort *s)
{
	const int	act_rb = s->act_node->list_index;
	const int	act_rrb = list_len(head_b) - act_rb;
	const int	act_ra = get_li(n_si_node(head_a, list_len(head_a) - 1)) + 1;
	const int	act_rra = list_len(head_a) - act_ra;

	if (act_ra == err)
		return (err);
	act_arr_reset(s);
	s->act_arr[_rb] = act_rb;
	s->act_arr[_ra] = act_ra;
	s->act_arr[_rrb] = act_rrb;
	s->act_arr[_rra] = act_rra;
	if (act_rb > act_ra)
		s->act_arr[_rr] = act_rb;
	else
		s->act_arr[_rr] = act_ra;
	if (act_rrb > act_rra)
		s->act_arr[_rrr] = act_rrb;
	else
		s->act_arr[_rrr] = act_rra;
	shortest_path(s);
	s->act_arr[_pa] = 1;
	return (pathmark_weight(s));
}

// Finds best path to get the act_node above the mark - pa stage
static double	pathmark_pa(t_list **head_a, t_list **head_b, t_sort *s)
{
	const int	act_rb = s->act_node->list_index;
	const int	act_rrb = list_len(head_b) - act_rb;
	const int	act_ra = get_li(n_iv_node(head_a, s->act_node->mark));
	const int	act_rra = list_len(head_a) - act_ra;

	if (act_ra == err)
		return (err);
	act_arr_reset(s);
	s->act_arr[_rb] = act_rb;
	s->act_arr[_ra] = act_ra;
	s->act_arr[_rrb] = act_rrb;
	s->act_arr[_rra] = act_rra;
	if (act_rb > act_ra)
		s->act_arr[_rr] = act_rb;
	else
		s->act_arr[_rr] = act_ra;
	if (act_rrb > act_rra)
		s->act_arr[_rrr] = act_rrb;
	else
		s->act_arr[_rrr] = act_rra;
	shortest_path(s);
	s->act_arr[_pa] = 1;
	return (pathmark_weight(s));
}

static void	choose_pathmark_pa(t_list **head_a, t_list **head_b, t_sort *s)
{
	int		i;
	int		best_act[8];
	double	cur_weight;
	t_list	*the_node;

	i = 0;
	s->act_weight = s->total_inp * 2;
	while (i < list_len(head_b))
	{
		s->act_node = n_li_node(head_b, i);
		if (s->act_node->mark == biggest)
			cur_weight = pathmark_big(head_a, head_b, s);
		else
			cur_weight = pathmark_pa(head_a, head_b, s);
		if (cur_weight > 0 && cur_weight < s->act_weight)
		{
			s->act_weight = cur_weight;
			the_node = s->act_node;
			copy_arr(best_act, s->act_arr, 8);
		}
		i++;
		// print_act_arr(s, i, cur_weight, the_node);// TEST!
	}
	return (ms_do_act(head_a, head_b, s, best_act));
}

// Chooses most efficient node to push to a out of the ones connected
// Size + amount of act, lower = better
void	mark_sort_pa(t_list **head_a, t_list **head_b, t_sort *s)
{
	int	act_ra;
	int	act_rra;

	while (list_len(head_b) > 0)
	{
		update_variable_index(head_a, head_b);
		choose_pathmark_pa(head_a, head_b, s);
		print_values(head_a, 'a');// TEST!
		print_values(head_b, 'b');// TEST!
	}
	if (check_sort_asc(head_a) == ok)
		return ;
	update_variable_index(head_a, head_b);
	act_ra = get_li(n_iv_node(head_a, 0));
	act_rra = list_len(head_a) - act_ra;
	act_arr_reset(s);
	if (act_ra < act_rra)
		s->act_arr[_ra] = act_ra;
	else
		s->act_arr[_rra] = act_rra;
	do_act_arr(head_a, head_b, s);
	return ;
}
