#include "push_swap.h"

// void	shortest_path(t_sort *s)
// {
// 	if (s->act_arr[_rb] <= s->act_arr[_rrb] && \
// 	s->act_arr[_ra] <= s->act_arr[_rra])
// 	{
// 		if (s->act_arr[_rb] > s->act_arr[_ra])
// 			s->act_arr[_rr] = s->act_arr[_ra]; 
// 		else
// 			s->act_arr[_rr] = s->act_arr[_rb];
// 	}
// 	else if (s->act_arr[_rb] >= s->act_arr[_rrb] && \
// 	s->act_arr[_ra] >= s->act_arr[_rra])
// 	{
// 		if (s->act_arr[_rrb] > s->act_arr[_rra])
// 			s->act_arr[_rrr] = s->act_arr[_rra];
// 		else
// 			s->act_arr[_rrr] = s->act_arr[_rrb];
// 	}
// 	init_shortest(s);
// }

static double	pathmark_weight(t_sort *s)
{
	const int	value = s->act_node->i_value;
	int			actions;
	int			i;

	i = 0;
	actions = 0;
	while (i < 8)
	{
		actions += s->act_arr[i];
		i++;
	}
	return (actions + (1 / (((value + 1) / (s->total_inp + 1)) * 100.0)));
}

// Finds best path to get the act_node above the mark - pa stage
static double	pathmark_pa(t_list **head_a, t_list **head_b, t_sort *s)
{
	const int	act_rb = s->act_node->list_index;
	const int	act_rrb = list_len(head_b) - act_rb;
	const int	act_ra = get_li(n_iv_node(head_a, s->act_node->mark));
	const int	act_rra = list_len(head_a) - act_ra;

	if (act_rb == err)
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
	s->act_weight = 0;
	while (i < list_len(head_b))
	{
		s->act_node = n_li_node(head_b, i);
		cur_weight = pathmark_pa(head_a, head_b, s);
		if (cur_weight >= 0 && (cur_weight < s->act_weight || i == 0))
		{
			s->act_weight = cur_weight;
			the_node = s->act_node;
			copy_arr(best_act, s->act_arr, 8);
			printf("%s>> mark %d[%d] = %f%s\n", DIMMED_F, s->act_node->i_value, i, cur_weight, RESET_F);// TEST!
		}
		i++;
	}
	return (do_act_arr(head_a, head_b, s));
}

// Chooses most efficient node to push to a out of the ones connected
// Size + amount of act, lower = better
void	mark_sort_pa(t_list **head_a, t_list **head_b, t_sort *s)
{
	while (list_len(head_b) > 0)
	{
		choose_pathmark_pa(head_a, head_b, s);
	}
}
