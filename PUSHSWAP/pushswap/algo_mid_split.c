#include "push_swap.h"

void	ms_big_to_b(t_list **head_a, t_list **head_b, t_sort *s, const short *arr)
{
	int	n;
	t_list	*tmp_a;
	t_list	*tmptmp_a;

	n = 0;
	tmp_a = *head_a;
	while (tmp_a != NULL && n++ < s->total_inputsize)
	{
		tmptmp_a = tmp_a->next;
		if (tmp_a->i_value > s->mid_iv_a)
		{
			if (tmp_a->list_index == 0)
				do_action(head_a, head_b, pb);
			else if (tmp_a->list_index == list_len(head_a))
				do_actions(head_a, head_b, 2, rra, pa); // LEFTOFF
			else
				do_action(head_a, head_b, ra);
		}
		tmp_a = tmptmp_a;
	}
	return ;
}

void	algo_midsplit(t_list **head_a, t_list **head_b, t_sort *s, const short *arr)
{
	while (!check_sort(head_a))
	{
		ms_big_to_b(head_a, head_b, s, arr);
	}
	return ;
}
