#include "push_swap.h"

static void	sorting(t_list **head_a, t_list **head_b, t_sort *s)
{
	if (check_sort_asc(head_a) != ok && s->total_inp > 3)
	{
		pb_stage(head_a, head_b, s);
		hardsort(head_a, head_b, st_a);
		pa_stage(head_a, head_b, s);
	}
	else if (check_sort_asc(head_a) != ok)
		hardsort(head_a, head_b, st_a);
}

static short	ft_pushswap(t_list **head_a, t_sort *s)
{
	t_list	*first;
	t_list	**head_b;

	first = NULL;
	head_b = &first;
	if (!*head_a)
		return (err);
	init_multiplier(s);
	sorting(head_a, head_b, s);
	free_list(head_a);
	free_list(head_b);
	return (ok);
}

int	main(int argc, char **argv)
{
	short	ret;
	t_list	*first;
	t_list	**head;
	t_sort	s;

	first = NULL;
	head = &first;
	if (argc <= 1)
		return (-1);
	if (parser(input_to_string(argc, argv), head) != ok)
		return (wr_a("Error"), -1);
	if (indexer(head) != ok)
		return (wr_a("Error"), -1);
	assign_mark(head);
	s.total_inp = list_len(head);
	if (ft_pushswap(head, &s) != ok)
		return (wr_a("Error"), -1);
	return (0);
}
