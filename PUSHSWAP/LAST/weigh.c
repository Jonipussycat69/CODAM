#include "push_swap.h"

/* get_cost:
*	Calculates the cost of moving each element of stack B into the correct
*	position in stack A.
*	Two costs are calculated:
*		weight_b represents the cost of getting the element to the top of the B stack
*		weight_a represents the cost of getting to the right position in stack A.
*	If the element is in the bottom half of the stack, the cost will be negative,
*	if it is in the top half, the cost is positive. 
*/
void	get_cost(t_list **a, t_list **b)
{
	t_list		*tmp_a;
	t_list		*tmp_b;
	const int	size_a = list_len(a);
	const int	size_b = list_len(b);

	tmp_a = *a;
	tmp_b = *b;
	while (tmp_b)
	{
		tmp_b->weight_b = tmp_b->place;
		if (tmp_b->place > size_b / 2)
			tmp_b->weight_b = (size_b - tmp_b->place) * -1;
		tmp_b->weight_a = tmp_b->to_be;
		if (tmp_b->to_be > size_a / 2)
			tmp_b->weight_a = (size_a - tmp_b->to_be) * -1;
		tmp_b = tmp_b->next;
	}
}

/* do_cheapest_move:
*	Finds the element in stack B with the cheapest cost to move to stack A
*	and moves it to the correct position in stack A.
*/
void	do_cheapest_move(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		cheapest;
	int		weight_a;
	int		weight_b;

	tmp = *b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->weight_a) + nb_abs(tmp->weight_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->weight_b) + nb_abs(tmp->weight_a);
			weight_a = tmp->weight_a;
			weight_b = tmp->weight_b;
		}
		tmp = tmp->next;
	}
	do_move(a, b, weight_a, weight_b);
}


/* push_all_save_three:
*	Pushes all the elements of stack a into stack b, except the three last ones.
*	Pushes the smaller values first, and then the larger values to help with
*	sorting efficiency.
*/
static void	push_all_save_three(t_list **a, t_list **b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*a)->index <= stack_size / 2)
		{
			do_pb(a, b);
			pushed++;
		}
		else
			do_ra(a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		do_pb(a, b);
		pushed++;
	}
}

/* shift_stack:
*	After the bulk of the stack is sorted, shifts stack a until the lowest
*	value is at the top. If it is in the bottom half of the stack, reverse
*	rotate it into position, otherwise rotate until it is at the top of the
*	stack.
*/
static void	shift_stack(t_list **a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*a);
	lowest_pos = get_lowest_index_position(a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			do_rra(a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_ra(a);
			lowest_pos--;
		}
	}
}

/* sort:
*	Sorting algorithm for a stack larger than 3.
*		Push everything but 3 numbers to stack B.
*		Sort the 3 numbers left in stack A.
*		Calculate the most cost-effective move.
*		Shift elements until stack A is in order.
*/
void	sort(t_list **a, t_list **b)
{
	push_all_save_three(a, b);
	tiny_sort(a);
	while (*b)
	{
		get_target_position(a, b);
		get_cost(a, b);
		do_cheapest_move(a, b);
	}
	if (!is_sorted(*a))
		shift_stack(a);
}

/* do_rev_rotate_both:
*	Reverse rotates both stack A and B until one of them is in position.
*	The given cost is negative since both positions are in the bottom half
*	of their respective stacks. The cost is increased as the stacks are
*	rotated, when one reaches 0, the stack has been rotated as far as possible
*	and the top position is correct.
*/
static void	do_rev_rotate_both(t_list **a, t_list **b,
												int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(a, b);
	}
}

/* do_rotate_both:
*	Rotates both stack A and B until one of them is in position.
*	The given cost is positive since both positions are in the top half
*	of their respective stacks. The cost is decreased as the stacks are
*	rotated, when one reaches 0, the stack has been rotated as far as possible
*	and the top position is correct.
*/
static void	do_rotate_both(t_list **a, t_list **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b);
	}
}

/* do_rotate_a:
*	Rotates stack A until it is in position. If the cost is negative,
*	the stack will be reverse rotated, if it is positive, it will be 
*	rotated.
*/
static void	do_rotate_a(t_list **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rra(a);
			(*cost)++;
		}
	}
}

/* do_rotate_b:
*	Rotates stack B until it is in position. If the cost is negative,
*	the stack will be reverse rotated, if it is positive, it will be 
*	rotated.
*/
static void	do_rotate_b(t_list **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rrb(b);
			(*cost)++;
		}
	}
}

/* do_move:
*	Chooses which move to make to get the B stack element to the correct
*	position in stack A.
*	If the costs of moving stack A and B into position match (i.e. both negative
*	of both positive), both will be	rotated or reverse rotated at the same time.
*	They might also be rotated separately, before finally pushing the top B element
*	to the top stack A.
*/
void	do_move(t_list **a, t_list **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	do_pa(a, b);
}
