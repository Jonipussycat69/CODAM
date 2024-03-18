#include "push_swap.h"

// Initializes first second last (fsl) (values of the fsl indexes of the list)
static int	*init_fsl(t_list **head)
{
	static int	fsl[4];

	fsl[0] = get_i_value(nth_node(head, 0));
	fsl[1] = get_i_value(nth_node(head, 1));
	fsl[2] = get_i_value(last_node(head));
	fsl[3] = 0;
	printf("\033[32m>|init_fsl| fsl = %d %d %d<\033[0m\n", fsl[0], fsl[1], fsl[2]);// TEST!
	return (fsl);
}
// First Second Last check: Checks which of the 3 is the biggest
// and arranges them in descending order
// the values in ret[4] will be an according order of: f, s, l
static char	*fsl_order(t_list **head, const char *fsl_arr)
{
	static char	ret[4];
	int			*fsl;
	int			i;
	int			j;
	int			place;

	i = 0;
	if (list_len(head) <= 3)
		return (NULL);
	fsl = init_fsl(head);
	while (i < 3)
	{
		place = 0;
		j = 0;
		while (j < 3)
		{
			if (fsl[i] < fsl[j])
				place++;
			j++;
		}
		ret[place] = fsl_arr[i];
		i++;
	}
	printf("\033[32m>|fsl_order| fsl(ret) = %s<\033[0m\n", ret);// TEST!
	ret[3] = '\0';
	return (ret);
}

// Chooses action to take based on fsl-a
// ra, sa or rra (before pb in algo_swap_push)
static short	first_s_a(t_list **head, const short *arr, const char *fsl_arr)
{
	const char	*fsl_a = fsl_order(head, fsl_arr);

	if (!fsl_a)
		return (err);
	if (fsl_a[0] == 's' && fsl_a[2] == 'f')
		return (ra);
	if (fsl_a[0] == 's')
		return (sa);
	if (fsl_a[0] == 'l')
		return (rra);
	return (inert);
}

// Determines if double-stack-action is applicable based on action-a and fsl-b
// It tries to sort b in an descending order
static short	first_s_b(t_list **head, short act_a, const short *arr, \
		const char *fsl_arr)
{
	const char	*fsl_b = fsl_order(head, fsl_arr);

	if (!fsl_b)
		return (act_a);
	if (act_a == ra)
	{
		if (fsl_b[2] == 'f')
			return (rr);
	}
	if (act_a == sa)
	{
		if (fsl_b[2] == 'f')
			return (ss);
	}
	if (act_a == rra)
	{
		if (fsl_b[0] == 'l')
			return (rrr);
	}
	return (act_a);
}

// Determines the actions based on fsl_order,
// the smallest gets pushed to b and tries to sort b (invertedly)
short	fsl_sort(t_list **head_a, t_list **head_b, t_sort *s, \
	const short *arr)
{
	const char	fsla[] = "fsl";
	short		ret;

	while (check_sort_asc(head_a) == err && list_len(head_a) > 3)
	{
		print_values(head_a, 'a');//TEST!
		print_values(head_b, 'b');//TEST!
		ret = first_s_b(head_b, first_s_a(head_a, arr, fsla), arr, fsla);
		if (ret == err)
			return (err);
		if (ret >= 0)
		{
			if (do_actions(head_a, head_b, 2, ret, pb) != ok)
				return (err);
		}
		else
		{
			if (do_action(head_a, head_b, pb) != ok)
				return (err);
		}
	}
	printf("\033[32m>|first_stage| list_len a = %d<\033[0m\n", list_len(head_a));// TEST!
	print_values(head_a, 'a');//TEST!
	print_values(head_b, 'b');//TEST!
	return (ok);
}

// 3 stage algorithm
// 1st stage: pushing lowest value possible with only 2 actions to b
// 2nd stage: hard-sorting the 3 remaining values in a
// 3rd stage: finding the most efficient value to push back to a
short	fsl_algo(t_list **head_a, t_list **head_b, t_sort *s, \
		const short *arr)
{
	if (list_len(head_a) > 3 && check_sort_asc(head_a) != ok)
	{
		if (fsl_sort(head_a, head_b, s, arr) != ok)
			return (err);
	}
	if (check_sort_asc(head_a) != ok)
	{
		if (hardsort(head_a, head_b, st_a))
			return (err);
	}
	if (check_sort_asc(head_a) != ok && list_len(head_b) == 0)
	{
		return (ok);
		// LEFTOFF third stage!
	}
	return (ok);
}
