#include "push_swap.h"

// Returns the code corresponding top the right action(s) for hc_action,
// code 'err' = no action
static short	hs_code(t_list **head_used)
{
	const short	big = get_li(n_si_node(head_used, 2));
	const short	small = get_li(n_si_node(head_used, 0));

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
void	hardsort(t_list **head_used, t_list **head_other, short used_stack)
{
	short	code;

	if (list_len(head_used) > 3 || list_len(head_used) < 2 || \
	check_sort_asc(head_used) == ok)
		return ;
	if (list_len(head_used) == 2 && used_stack == st_a)
		return (hs_action(head_used, head_other, 4, used_stack));
	if (list_len(head_used) == 2 && used_stack == st_b)
		return (hs_action(head_other, head_used, 4, used_stack));
	while (check_sort_asc(head_used) != ok)
	{
		update_variable_index(head_used, head_other);
		code = hs_code(head_used);
		if (code == err)
			return ;
		if (used_stack == st_a)
			hs_action(head_used, head_other, code, used_stack);
		else
			hs_action(head_other, head_used, code, used_stack);
	}
	return ;
}
