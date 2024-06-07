/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/06 13:30:59 by jdobos        #+#    #+#                 */
/*   Updated: 2024/06/07 15:26:06 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		s->act_arr[_rra] = list_len(a) - i;
	return (do_act_arr(a, b, s));
}

void	pb_stage(t_list **a, t_list **b)
{
	while (list_len(a) > 3 && check_sort_asc(a) != ok)
		do_action(a, b, pb);
}

// algo that calculates all the steps for each node.
// just looking at the right place it should go in a
// (inbetween the closest bigger and smaller number).
// at the end a should be rotated so it starts at the smallest
// and be sorted in descending order and b should be empty.
void	pa_stage(t_list **a, t_list **b, t_sort *s)
{
	t_list	*node;
	int		weight;
	int		chosen_weight;
	t_list	*chosen_node;

	while (list_len(b))
	{
		s->index = 0;
		chosen_weight = 0;
		node = *b;
		while (node != NULL)
		{
			weight = weigh(a, b, s, node);
			if (weight <= chosen_weight || s->index == 0)
			{
				chosen_weight = weight;
				chosen_node = node;
				s->the_index = s->index;
			}
			s->index++;
			node = node->next;
		}
		execute_act(a, b, s, chosen_node);
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
