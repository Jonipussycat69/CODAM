#include "push_swap.h"

// 3 stage algorithm
// 1st stage: pushing lowest value possible with only 2 actions to b
// 2nd stage: hard-sorting the 3 remaining values in a
// 3rd stage: finding the most efficient value to push back to a
short	algo_swap_push(t_list **head_a, t_list **head_b, t_sort *s, \
		const short *arr)
{
	if (list_len(head_a) > 3 && check_sort(head_a) != ok)
	{
		if (first_stage(head_a, head_b, s, arr))
			return (err);
	}
	if (check_sort(head_a) != ok)
	{
		if (hardsort(head_a, head_b, a))
			return (err);
	}
	if (check_sort(head_a) != ok && list_len(head_b) == 0)
	{
		// LEFTOFF third stage!
	}
	return (ok);
}
