#include "push_swap.h"

// Parses the act_arr and executes ra/b at pre_actions
static short	exec_pre_r(t_list **head_a, t_list **head_b, t_sort *s)
{
	short		i;
	const short	action[] = {ra, rb, rra, rrb, pa, pb};

	i = 0;
	while (i < 6)
	{
		if (i < 2 || i > 3)
			repeat_pre_act(head_a, head_b, s->act_arr[i], action[i]);
		i++;
	}
	return (ok);
}

// Parses the act_arr and executes rra/b at pre_actions
static short	exec_pre_rr(t_list **head_a, t_list **head_b, t_sort *s)
{
	short		i;
	const short	action[] = {ra, rb, rra, rrb, pa, pb};

	i = 0;
	while (i < 6)
	{
		if (i > 1)
			repeat_pre_act(head_a, head_b, s->act_arr[i], action[i]);
		i++;
	}
	return (ok);
}

// Reverts the ra/b list changes made in precalc
static short	revert_pre_r(t_list **head_a, t_list **head_b, t_sort *s)
{
	short		i;
	const short	action[] = {rra, rrb, ra, rb, pb, pa};

	i = 5;
	while (i >= 0)
	{
		if (i < 2 || i > 3)
			repeat_pre_act(head_a, head_b, s->act_arr[i], action[i]);
		i--;
	}
	return (ok);
}

// Reverts the rra/b list changes made in precalc
static short	revert_pre_rr(t_list **head_a, t_list **head_b, t_sort *s)
{
	short		i;
	const short	action[] = {rra, rrb, ra, rb, pb, pa};

	i = 5;
	while (i >= 0)
	{
		if (i > 1)
			repeat_pre_act(head_a, head_b, s->act_arr[i], action[i]);
		i--;
	}
	return (ok);
}

double	precalc(t_list **head_a, t_list **head_b, t_sort *s, short stage)
{
	double	sortedness_r;
	double	sortedness_rr;

	exec_pre_r(head_a, head_b, s);
	sortedness_r = sortedness_gl(head_a, head_b, s, stage);
	revert_pre_r(head_a, head_b, s);
	exec_pre_rr(head_a, head_b, s);
	sortedness_rr = sortedness_gl(head_a, head_b, s, stage);
	revert_pre_rr(head_a, head_b, s);
	if (sortedness_r > sortedness_rr)
	{
		s->rr_actions = inert;
		return (sortedness_r);
	}
	else
	{
		s->r_actions = inert;
		return (sortedness_rr);
	}
}
