#include "push_swap.h"

static t_list	*check_sort(t_list **head)
{
	t_list	*tmp;
	int		prev_index;
	
	if (!*head)
		return (NULL);
	tmp = *head;
	while (tmp != NULL)
	{
		prev_index = tmp->i_value;
		tmp = tmp->next;
		if (tmp->i_value < prev_index)
			return (tmp);
	}
	return (head);
}

void	flagger(t_list **head, t_sort *s)
{
	// WHAT WILL THE FLAG INDICATE?
	return ;
}

static void	innit_sorting_var(t_list **head_a, t_list **head_b, t_sort *s)
{
	list_indexer(head_a);
	list_indexer(head_b);
	s->stack_a_len = list_len(head_a);
	s->stack_b_len = list_len(head_b);
	assign_mid(head_a, head_b, s);
	assign_large(head_a, head_b, s);
}

void	small_algo(t_list **head_a, t_list **head_b, t_sort *s, short *arr)
{
	innit_sorting_var(head_a, head_b, s);
	flagger(head_a, s);
	flagger(head_b, s);
	return ;
}

void	midsplit_algo(t_list **head_a, t_list **head_b, t_sort *s, short *arr)
{
	int	n;
	t_list	*tmp_a;
	t_list	*tmptmp_a;

	n = 0;
	tmp_a = *head_a;
	innit_sorting_var(head_a, head_b, s);
	while (tmp_a != NULL && n++ < s->total_inputsize)
	{
		tmptmp_a = tmp_a->next;
		if (tmp_a->i_value > s->mid_iv_a)
		{
			if (tmp_a->list_index == 0)
				do_action(head_a, head_b, pb);
			else if (tmp_a->list_index == list_len(head_a))
				do_action(head_a, head_b, pb);
			else if (tmp_a->list_index == 0)
				do_action(head_a, head_b, pb);
		}
		tmp_a = tmptmp_a;
	}
	return ;
}

void	big_to_b(t_list **head_a, t_list **head_b, t_sort *s, short *arr)
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
