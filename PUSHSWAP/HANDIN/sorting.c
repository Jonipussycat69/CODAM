#include "push_swap.h"

void	smallest_to_top(t_list **a, t_list **b, t_sort *s)
{
	t_list	*node;
	int		i;

	node = *a;
	i = 0;
	while (node != NULL && node->n_i != 0)
	{
		node = node->next;
		i++;
	}
	act_arr_reset(s);
	if (i <= list_len(a) / 2)
		s->act_arr[_ra] = i;
	else
		s->act_arr[_rra] = list_len(a) - i + 1;
	return (do_act_arr(a, b, s));
}

void	assign_best(int weight, t_list *node, t_sort *s)
{
	if (s->the_weight == weight && node->n_i > s->the_node->n_i)
		return ;
	s->the_weight = weight;
	s->the_node = node;
	s->the_index = s->index;
	return ;
}

void	pb_stage(t_list **a, t_list **b, t_sort *s)
{
	while (list_len(a) > 3 && check_sort_asc(a) != ok)
		do_action(a, b, pb);
}

// algo that calculates all the steps for each node.
// just looking at the right place it should go in a (inbetween the closest bigger and smaller number).
// node->ind = amound of r, node->ind - total list_len = rr (so it will be negative).
// at the end a should be rotated so it starts at the smallest and be sorted in descending order and b should be empty.
void	pa_stage(t_list **a, t_list **b, t_sort *s)
{
	t_list	*node;
	int		weight;

	while (list_len(b))
	{
		s->index = 0;
		weight = 0;
		node = *b;
		while (node != NULL)
		{
			if (weigh(a, b, s, node) <= weight || s->index == 0)
				assign_best(weigh(a, b, s, node), node, s);
			s->index++;
			node = node->next;
		}
		print_values(a, b, s);// TEST
		printf(">> best-> %i\n", s->the_node->n_i);// TEST
		execute_act(a, b, s, s->the_node);
	}
	smallest_to_top(a, b, s);
}

// Hard-sorting for 2 or 3 value list (stack a)
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
