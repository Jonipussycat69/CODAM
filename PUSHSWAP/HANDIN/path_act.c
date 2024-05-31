#include "push_swap.h"

static void	exe_rrr(t_sort *s, int rr_a, int rr_b)
{
	if (rr_a > rr_b)
		s->act_arr[_rra] = rr_a - rr_b;
	else
		s->act_arr[_rrb] = rr_b - rr_a;
	s->act_arr[_rrr] = sn(rr_a, rr_b);
}

static void	exe_rr(t_sort *s, int r_a, int r_b)
{
	if (r_a > r_b)
		s->act_arr[_ra] = r_a - r_b;
	else
		s->act_arr[_rb] = r_b - r_a;
	s->act_arr[_rr] = sn(r_a, r_b);
}

void	execute_act(t_list **a, t_list **b, t_sort *s, t_list *node)
{
	const int	r_b = s->the_index;
	const int	rr_b = list_len(b) - r_b;
	const int	r_a = rotate_amount_a(a, node->num);
	const int	rr_a = list_len(a) - r_a;

	printf(">> ra: %i, rra: %i, rb: %i, rrb: %i\n", r_a, rr_a, r_b, rr_b);// TEST
	act_arr_reset(s);
	if (r_a - rr_a >= 0 && r_b - rr_b >= 0)
		exe_rrr(s, rr_a, rr_b);
	else if (r_a - rr_a <= 0 && r_b - rr_b <= 0)
		exe_rr(s, r_a, r_b);
	else
	{
		if (r_a > rr_a)
			s->act_arr[_rra] = rr_a;
		else
			s->act_arr[_ra] = r_a;
		if (r_b > rr_b)
			s->act_arr[_rrb] = rr_b;
		else
			s->act_arr[_rb] = r_b;
	}
	s->act_arr[_pa] = 1;
	do_act_arr(a, b, s);
}

// looks at the the amount of actions needed in both stacks
// to get the node in the correct spot.
int	weigh(t_list **a, t_list **b, t_sort *s, t_list *node)
{
	const int	r_b = s->index;
	const int	rr_b = list_len(b) - r_b;
	const int	r_a = rotate_amount_a(a, node->num);
	const int	rr_a = list_len(a) - r_a;

	printf(">> ra: %i, rra: %i, rb: %i, rrb: %i\n", r_a, rr_a, r_b, rr_b);// TEST
	if (r_a - rr_a >= 0 && r_b - rr_b >= 0)
		return (bn(rr_a, rr_b) + 1);
	if (r_a - rr_a <= 0 && r_b - rr_b <= 0)
		return (bn(r_a, r_b) + 1);
	else
		return (sn(r_a, rr_a) + sn(r_b, rr_b) + 1);
}
