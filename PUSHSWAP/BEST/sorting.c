#include "push_swap.h"

void	biggest_to_top(t_list **a, t_list **b, t_sort *s)
{
	t_list	*node;
	int		biggest;
	int		biggest_ind;
	int		i;

	node = *b;
	i = 0;
	biggest = node->num;
	biggest_ind = i;
	while (node != NULL)
	{
		if (node->num > biggest)
		{
			biggest = node->num;
			biggest_ind = i;
		}
		node = node->next;
	}
	if (biggest_ind <= list_len(b) / 2)
		s->act_arr[_rb] = biggest_ind;
	else
		s->act_arr[_rrb] = list_len(b) - biggest_ind + 1;
	return (act_arr_reset(s), do_act_arr(a, b, s));
}

// algo that calculates all the steps for each node, NO connecting nodes!
// just looking at the right place it should go in b (inbetween the closest bigger and smaller number).
// node->ind = amound of r, node->ind - total list_len = rr (so it will be negative).
// It pushes to b until there are only 3 num left in a.
// at the end b should be rotated so it starts at the biggest and be sorted in descending order
void	pb_stage(t_list **a, t_list **b, t_sort *s)
{
	t_list	*node;
	t_list	*lightest;
	double	weight;

	while (list_len(a) > 3 && check_sort_asc(a) != ok)
	{
		s->index = 0;
		weight = 0;
		node = *a;
		while (node != NULL)
		{
			printf("loop -> %i pa sorting\n", s->index);// TEST
			if (weigh(a, b, s, node) < weight || s->index == 0)
			{
				weight = weigh(a, b, s, node);
				lightest = node;
			}
			s->index++;
			node = node->next;
		}
		execute_act(a, b, s, lightest);
		printf("biggest to top -> pa sorting\n");// TEST
	}
	biggest_to_top(a, b, s);
}

// Pushes evrything back to stack a, and reverse rotates the remaining 3 num on top at the right time.
// when this stage is done b should be empty.
// when this stage is done a should be sorted in ascending order.
void	pa_stage(t_list **a, t_list **b, t_sort *s)
{
	t_list	*last_a;

	while (list_len(b) > 0)
	{
		printf("loop -> 0 pa sorting\n");// TEST
		last_a = last_node(a);
		printf("loop -> 1 pa sorting\n");// TEST
		if (last_a->num < (*b)->num && (list_len(b) <= 1 || last_a->num > (*b)->next->num))
			do_actions(a, b, 2, pa, rra);
		else
			do_action(a, b, pa);
	}
}

// Hard-sorting for 2 or 3 value list
void	hardsort(t_list **a, t_list **b)
{
	if (list_len(a) > 3 || list_len(a) < 2 || \
	check_sort_asc(a) == ok)
		return ;
	if (list_len(a) == 2 || ((*a)->num > (*a)->next->num \
	&& (*a)->num < (*a)->next->next->num))
		return (do_action(a, b, sa));
	if ((*a)->num < (*a)->next->num && (*a)->num < (*a)->next->next->num)
		return (do_actions(a, b, 2, sa, ra));
	if ((*a)->num > (*a)->next->num && (*a)->num > (*a)->next->next->num \
	&& (*a)->next->num < (*a)->next->next->num)
		return (do_action(a, b, ra));
	if ((*a)->num > (*a)->next->num && (*a)->num > (*a)->next->next->num \
	&& (*a)->next->num > (*a)->next->next->num)
		return (do_actions(a, b, 2, ra, sa));
	if ((*a)->num < (*a)->next->num && (*a)->num > (*a)->next->next->num)
		return (do_actions(a, b, 2, ra, ra));
	return ;
}
