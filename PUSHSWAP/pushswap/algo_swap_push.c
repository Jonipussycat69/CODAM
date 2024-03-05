#include "push_swap.h"

short	fsl_check(t_list **head)
{
	return (ok);
}

short	first_stage(t_list **head_a, t_list **head_b, t_sort *s, short arr)
{
	return (ok);
}

short	algo_swap_push(t_list **head_a, t_list **head_b, t_sort *s, short arr)
{
	// stage 1: pushing from a to b
	while (check_sort(head_a) == err && list_len(head_a) > 3)
	{
		s->ret_a = first_stage(head_a, head_b, s, arr);
		if (s->ret_a == err)
			return (err);
		if (s->ret_a >= 0)
			do_actions(head_a, head_b, 2, s->ret_a, pb);
		else
			do_action(head_a, head_b, pb);
	}
	// stage 2: marking values in b with the revious value done in main
	// stage 3: pushing from b to a
	
	return ;
}
