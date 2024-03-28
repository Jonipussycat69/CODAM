#include "push_swap.h"

void	do_a(t_list **head_a, t_list **head_b, short action)
{
	if (action == sa)
		return (wr_a("sa"), swap(head_a));
	if (action == sb)
		return (wr_a("sb"), swap(head_b));
	if (action == pa)
		return (wr_a("pa"), push(head_a, head_b, pa));
	if (action == pb)
		return (wr_a("pb"), push(head_a, head_b, pb));
	if (action == ra)
		return (wr_a("ra"), rotate(head_a));
	if (action == rb)
		return (wr_a("rb"), rotate(head_b));
	if (action == rra)
		return (wr_a("rra"), r_rotate(head_a));
	if (action == rrb)
		return (wr_a("rrb"), r_rotate(head_b));
	if (action == ss)
		return (wr_a("ss"), swap_both(head_a, head_b));
	if (action == rr)
		return (wr_a("rr"), rotate_both(head_a, head_b));
	if (action == rrr)
		return (wr_a("rrr"), r_rotate_both(head_a, head_b));
	return ;
}

void	do_actions(t_list **head_a, t_list **head_b, int amount, ...)
{
	va_list	actions;
	int		iteration;

	va_start(actions, amount);
	iteration = 0;
	while (iteration++ < amount)
	{
		do_a(head_a, head_b, va_arg(actions, int));
	}
	va_end(actions);
	return ;
}

void	repeat_action(t_list **head_a, t_list **head_b, int iter, short act)
{
	while (iter-- > 0)
	{
		do_a(head_a, head_b, act);
	}
	return ;
}

void	do_act_arr(t_list **head_a, t_list **head_b, t_sort *s)
{
	short		i;
	const short	actions[] = {ra, rb, rra, rrb, rr, rrr, pa, pb};

	i = 0;
	while (i < 8)
	{
		repeat_action(head_a, head_b, s->act_arr[i], actions[i]);
		i++;
	}
	return ;
}

short	double_act(t_list **head_a, t_list **head_b, short act)// Obselete??
{
	stack_indexer(head_b);
	if (act == ra)
	{
		if (get_si(*head_b) < get_si(last_node(head_b)))
			return (rr);
	}
	if (act == rra)
	{
		if (get_si(*head_b) < get_si(last_node(head_b)))
			return (rrr);
	}
	stack_indexer(head_a);
	if (act == rb)
	{
		if (get_si(*head_a) > get_si(last_node(head_a)))
			return (rr);
	}
	if (act == rrb)
	{
		if (get_si(*head_a) > get_si(last_node(head_a)))
			return (rrr);
	}
	return (act);
}
