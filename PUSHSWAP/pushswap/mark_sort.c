#include "push_swap.h"

static double	pathmark_weight(t_sort *s)
{
	const double	value = s->act_node->i_value;
	int				actions;
	int				i;

	i = 0;
	actions = 0;
	while (i < 8)
	{
		actions += s->act_arr[i];
		i++;
	}
	return ((double)actions + (1 / \
	(((value + 1) / (s->total_inp + 1)) * 100.0)));
}

static void	do_mark_sort(t_list **head_a, t_list **head_b, t_sort *s, int mark)
{
	ms_do_act_arr(head_a, head_b, s);
	if (mark == biggest)
		do_action(head_a, head_b, ra);
	return ;
}

static double	pathmark_big(t_list **head_a, t_list **head_b, t_sort *s)
{
	const int	act_rb = s->act_node->list_index;
	const int	act_rrb = list_len(head_b) - act_rb;

	act_arr_reset(s);
	if (act_rb < act_rrb)
		s->act_arr[_rb] = act_rb;
	else
		s->act_arr[_rrb] = act_rrb;
	s->act_arr[_pa] = 1;
	return (pathmark_weight(s) + 1);
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
			printf("%s>> mark %d[%d] = %f%s\n", DIMMED_F, s->act_node->i_value, i, cur_weight, RESET_F);// TEST!
		}
		i++;
	}
	return (do_mark_sort(head_a, head_b, s, the_node->mark));
}

// Chooses most efficient node to push to a out of the ones connected
// Size + amount of act, lower = better
void	mark_sort_pa(t_list **head_a, t_list **head_b, t_sort *s)
{
	while (list_len(head_b) > 0)
	{
		update_variable_index(head_a, head_b);
		choose_pathmark_pa(head_a, head_b, s);
		// print_values(head_a, 'a');// TEST!
		// print_values(head_b, 'b');// TEST!
	}
}
