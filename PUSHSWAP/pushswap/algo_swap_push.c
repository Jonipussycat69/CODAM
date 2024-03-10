#include "push_swap.h"


int	*get_fsl(t_list **head)
{
	static int	fsl[4];

	fsl[0] = get_index(nth_node(head, 0));
	fsl[1] = get_index(nth_node(head, 1));
	fsl[2] = get_index(last_node(head));
	fsl[3] = 0;
	return (fsl);
}
// First Second Last check: Checks which of the 3 is the biggest
char	*fsl_order(t_list **head)
{
	static char	ret[4];
	int			*fsl;
	int			i;
	int			j;
	int			place;

	i = 0;
	fsl = get_fsl(head);
	while (i < 4)
	{
		place = 0;
		j = 0;
		while (j < 4)
		{
			if (fsl[i] < fsl[j])
				place++;
			j++;
		}
		ret[place] = i;
		i++;
	}
	ret[3] = '\0';
	return (ret);
}
// Determines the actions based on fsl_order, the smallest gets pushed to b and b is as (invertedly) sorted as possible
short	first_stage(t_list **head_a, t_list **head_b, t_sort *s, short arr)
{
	const char	*fsl_a = fsl_order(head_b);
	const char	*fsl_b = fsl_order(head_b);

	// Here write all the possibible combinations
	if (fsl_a[0] == fsl_b[0] && fsl_a[1] == fsl_b[1] && fsl_a[2] == fsl_b[2])
	{
	// LEFTOFF
	}
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
	
	return (ok);
}
