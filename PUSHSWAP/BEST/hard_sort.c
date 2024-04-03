#include "push_swap.h"

// Returns the code corresponding top the right action(s) for hc_action,
// code 'err' = no action
static short	hs_code(t_list **a)
{
	const short	big = get_li(n_si_node(a, 2));
	const short	small = get_li(n_si_node(a, 0));

	if (big == 0 && small == 2)
		return (1);
	if (big == 1 && small == 0)
		return (2);
	if (small == 2)
		return (3);
	if (big == 2 && small == 1)
		return (4);
	if (big == 0)
		return (5);
	return (err);
}

// Chooses action based on hs_code return
static void	hs_action(t_list **head_a, t_list **head_b, short code, short stack)
{
	const short	act[] = {sa, sb, ra, rb, rra, rrb};

	if (code == 1)
		return (do_actions(head_a, head_b, 2, act[2 + stack], act[0 + stack]));
	if (code == 2)
		return (do_actions(head_a, head_b, 2, act[4 + stack], act[0 + stack]));
	if (code == 3)
		return (do_action(head_a, head_b, act[4 + stack]));
	if (code == 4)
		return (do_action(head_a, head_b, act[0 + stack]));
	if (code == 5)
		return (do_action(head_a, head_b, act[2 + stack]));
	return ;
}

// Hard-sorting for 2 or 3 value list
void	hardsort(t_list **a, t_list **b)
{
	short	code;

	if (list_len(a) > 3 || list_len(a) < 2 || \
	check_sort_asc(a) == ok)
		return ;
	if (list_len(a) == 2)
		return (do_action(a, b, sa));
	if ((*a)->num < (*a)->next->num && (*a)->num < (*a)->next->next->num)
		return (do_actions(a, b, 2, sa, ra));
	if ((*a)->num > (*a)->next->num && (*a)->num > (*a)->next->next->num \
	&& (*a)->next->num < (*a)->next->next->num)
		return (do_actions(a, b, 2, ra, sa));// LEFTOFF
	return ;
}
