#include "push_swap.h"

// First Second Last check: Checks which of the 3 is the biggest
static char	*fsl_check(t_list **head)
{
	static char	ret[4];
	int			fsl[4];
	int			i;
	int			j;
	int			k;

	fsl[0] = get_index(nth_node(head, 0));
	fsl[1] = get_index(nth_node(head, 1));
	fsl[2] = get_index(last_node(head));
	fsl[3] = 0;

	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (fsl[i] < fsl[j])
				break ;
			j++;
		}
		if (j == 4)
		{
			fsl[i] = 0;
			ret[k] = i;
			k++;
		}
		i++;
	}
	return (ret);
}
// Determines the actions based on fsl_check, so the smallest gets pushed to b and b is as (invertedly) sorted as possible
short	first_stage(t_list **head_a, t_list **head_b, t_sort *s, short arr)
{
	// LEFTOFF
	const char	*ret_fsl_a = fsl_check(head_b);
	const char	*ret_fsl_b = fsl_check(head_b);

	// Here write all the possibible combinations
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
