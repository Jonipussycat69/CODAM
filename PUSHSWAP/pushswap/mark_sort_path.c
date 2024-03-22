#include "push_swap.h"

void	init_shortest(t_sort *s, int *tmp, short *act)
{
	const int	act_one = s->act_arr[act[0]];
	int			act_two;

	if (act[1] == -1)
		return (copy_arr(s->act_arr, tmp, 8));
	act_two = s->act_arr[act[1]];
	act_arr_reset(s);
	s->act_arr[act[0]] = act_one;
	s->act_arr[act[1]] = act_two;
}

void	set_rr(t_sort *s, int *tmp)
{
	if (s->act_arr[_ra] > s->act_arr[_rb])
	{
		tmp[_rr] = s->act_arr[_rb];
		tmp[_ra] = s->act_arr[_ra] - s->act_arr[_rb];
	}
	else
	{
		tmp[_rr] = s->act_arr[_ra];
		tmp[_rb] = s->act_arr[_rb] - s->act_arr[_ra];
	}
}

void	set_rrr(t_sort *s, int *tmp)
{
	if (s->act_arr[_rra] > s->act_arr[_rrb])
	{
		tmp[_rrr] = s->act_arr[_rrb];
		tmp[_rra] = s->act_arr[_rra] - s->act_arr[_rrb];
	}
	else
	{
		tmp[_rrr] = s->act_arr[_rra];
		tmp[_rrb] = s->act_arr[_rrb] - s->act_arr[_rra];
	}
}

void	init_shortest_prepare(t_sort *s, short *act)
{
	int	tmp[8];

	set_null(tmp, 8);
	if (act[0] == _rr)
		set_rr(s, tmp);
	else if (act[0] == _rrr)
		set_rrr(s, tmp);
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
