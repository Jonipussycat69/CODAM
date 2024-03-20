#include "push_swap.h"

void	ms_rep_action(t_list **head_a, t_list **head_b, int iter, short act)
{
	while (iter-- > 0)
	{
		do_action(head_a, head_b, act);
	}
	return ;
}

void	ms_do_act_arr(t_list **head_a, t_list **head_b, t_sort *s)
{
	short		i;
	const short	actions[] = {ra, rb, rra, rrb, pa, pb, rr, rrr};

	i = 0;
	while (i < 6)
	{
		ms_rep_action(head_a, head_b, s->act_arr[i], actions[i]);
		i++;
	}
	return ;
}

void	init_shortest(t_sort *s, int *tmp, short *act)
{
	const int	one = s->act_arr[act[0]];
	const int	two = s->act_arr[act[1]];

	if (tmp[_rr] || tmp[_rrr])
		return (copy_arr(s->act_arr, tmp, 8));
	act_arr_reset(s);
	s->act_arr[act[0]] = one;
	s->act_arr[act[1]] = two;
}

void	init_shortest_prepare(t_sort *s, short *act)
{
	int	tmp[8];

	set_null(tmp, 8);
	if (act[0] == _rr)
	{
		tmp[_rr] = s->act_arr[_ra];
		tmp[_ra] = s->act_arr[_rb] - s->act_arr[_ra];
		if (s->act_arr[_ra] > s->act_arr[_rb])
		{
			tmp[_rr] = s->act_arr[_rb];
			tmp[_ra] = s->act_arr[_ra] - s->act_arr[_rb];
		}
	}
	else if (act[0] == _rrr)
	{
		tmp[_rr] = s->act_arr[_ra];
		tmp[_ra] = s->act_arr[_rb] - s->act_arr[_ra];
		if (s->act_arr[_ra] > s->act_arr[_rb])
		{
			tmp[_rr] = s->act_arr[_rb];
			tmp[_ra] = s->act_arr[_ra] - s->act_arr[_rb];
		}
	}
	init_shortest(s, tmp, act);
}

void	shortest_path(t_sort *s)
{
	int		comp;
	short	act[2];

	act[0] = _rrr;
	act[1] = -1;
	comp = s->act_arr[_rrr];
	if (s->act_arr[_rr] < s->act_arr[_rrr])
	{
		act[0] = _rr;
		comp = s->act_arr[_rr];
	}
	if (s->act_arr[_ra] + s->act_arr[_rrb] < comp)
	{
		act[0] = _ra;
		act[1] = _rrb;
	}
	if (s->act_arr[_rra] + s->act_arr[_rb] < comp)
	{
		act[0] = _rra;
		act[1] = _rb;
	}
	init_shortest_prepare(s, act);
}
