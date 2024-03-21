#include "push_swap.h"

// Utils for precalc, eg: a pre_actions function
void	pre_action(t_list **head_a, t_list **head_b, short action)
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
	return ;
}

void	pre_actions(t_list **head_a, t_list **head_b, int amount, ...)
{
	va_list	actions;
	int		iteration;

	va_start(actions, amount);
	iteration = 0;
	while (iteration++ < amount)
	{
		pre_action(head_a, head_b, double_act(head_a, head_b, \
		va_arg(actions, int)));
	}
	va_end(actions);
	return ;
}

void	repeat_pre_act(t_list **head_a, t_list **head_b, int iter, short act)
{
	while (iter-- > 0)
	{
		pre_action(head_a, head_b, double_act(head_a, head_b, act));
	}
	return ;
}
