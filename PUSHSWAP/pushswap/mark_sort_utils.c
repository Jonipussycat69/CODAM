#include "push_swap.h"

void	ms_rep_action(t_list **head_a, t_list **head_b, int iter, short act)
{
	while (iter-- > 0)
	{
		do_action(head_a, head_b, act);
	}
	return ;
}

void	ms_do_act(t_list **head_a, t_list **head_b, t_sort *s, int *act)
{
	short		i;
	const short	actions[] = {ra, rb, rra, rrb, rr, rrr, pa, pb};

	i = 0;
	while (i < 8)
	{
		ms_rep_action(head_a, head_b, act[i], actions[i]);
		i++;
	}
	return ;
}

double	pathmark_weight(t_sort *s)
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
