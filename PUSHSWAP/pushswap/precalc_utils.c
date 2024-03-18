#include "push_swap.h"

// Utils for precalc, eg: a pre_actions function
short	pre_action(t_list **head_a, t_list **head_b, short action)
{
	if (action == sa)
		return (swap(head_a));
	if (action == sb)
		return (swap(head_b));
	if (action == pa)
		return (push(head_a, head_b, pa));
	if (action == pb)
		return (push(head_a, head_b, pb));
	if (action == ra)
		return (rotate(head_a));
	if (action == rb)
		return (rotate(head_b));
	if (action == rra)
		return (r_rotate(head_a));
	if (action == rrb)
		return (r_rotate(head_b));
	if (action == ss)
		return (swap_both(head_a, head_b));
	if (action == rr)
		return (rotate_both(head_a, head_b));
	if (action == rrr)
		return (r_rotate_both(head_a, head_b));
	return (err);
}

short	pre_actions(t_list **head_a, t_list **head_b, int amount, ...)
{
	va_list	actions;
	int		iteration;

	va_start(actions, amount);
	iteration = 0;
	while (iteration++ < amount)
	{
		if (pre_action(head_a, head_b, va_arg(actions, int)) == err)
			return (err);
	}
	va_end(actions);
	return (ok);
}

short	repeat_pre_act(t_list **head_a, t_list **head_b, int iter, short act)
{
	while (iter-- > 0)
	{
		if (pre_action(head_a, head_b, act) == err)
			return (err);
	}
	return (ok);
}

// Parses the act_arr and executes it at pre_actions
short	parse_pre_arr(t_list **head_a, t_list **head_b, t_sort *s)
{
	short		i;
	const short	actions[] = {ra, rb, rra, rrb, rr, rrr, pa, pb};

	i = 0;
	while (i < 8)
	{
		if (repeat_pre_act(head_a, head_b, s->pre_arr[i], actions[i]) != ok)
			return (err);
		i++;
	}
	return (ok);
}

// Reverts the list changes made in precalc
short	revert_calc(t_list **head_a, t_list **head_b, t_sort *s)
{
	short		i;
	const short	actions[] = {rra, rrb, ra, rb, rrr, rr, pb, pa};

	i = 7;
	while (i >= 0)
	{
		if (repeat_pre_act(head_a, head_b, s->pre_arr[i], actions[i]) != ok)
			return (err);
		i--;
	}
	return (ok);
}
