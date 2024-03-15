#include "push_swap.h"

// Returns 'ok' if stack is sorted ascending, 'err' if not
short	check_sort_asc(t_list **head)
{
	t_list	*tmp;
	int		prev_index;
	
	if (!*head)
		return (err);
	tmp = *head;
	while (tmp->next != NULL)
	{
		prev_index = tmp->i_value;
		tmp = tmp->next;
		if (tmp->i_value < prev_index)
			return (err);
	}
	return (ok);
}

// Returns 'ok' if stack is sorted descending, 'err' if not
short	check_sort_des(t_list **head)
{
	t_list	*tmp;
	int		prev_index;
	
	if (!*head)
		return (err);
	tmp = *head;
	while (tmp->next != NULL)
	{
		prev_index = tmp->i_value;
		tmp = tmp->next;
		if (tmp->i_value > prev_index)
			return (err);
	}
	return (ok);
}

double	sortedness_asc(t_list **head)
{
	long			total_dif;
	int				hold;
	double			sorted;
	const double	len = list_len(head);
	t_list			*tmp;

	if (!head || !*head || (int)len < 2)
		return (0);
	tmp = *head;
	total_dif = 0;
	stack_indexer(head);
	while (tmp->next != NULL)
	{
		hold = tmp->stack_iv;
		tmp = tmp->next;
		hold = tmp->stack_iv - hold;
		if (hold < 0)
			hold *= -2;
		total_dif += hold;
	}
	sorted = ((len - 1.0) / (double)total_dif) * 100.00;
	sorted = (((len / ((double)total_dif + 1.0)) * 100.00) + sorted) / 2.0;
	return (sorted);
}

double	sortedness_des(t_list **head)
{
	long			total_dif;
	int				hold;
	double			sorted;
	const double	len = list_len(head);
	t_list			*tmp;

	if (!head || !*head || (int)len < 2)
		return (0);
	tmp = *head;
	total_dif = 0;
	stack_indexer(head);
	while (tmp->next != NULL)
	{
		hold = tmp->stack_iv;
		tmp = tmp->next;
		hold = hold - tmp->stack_iv;
		if (hold < 0)
			hold *= -2;
		total_dif += hold;
	}
	sorted = ((len - 1.0) / (double)total_dif) * 100.00;
	sorted = (((len / ((double)total_dif + 1.0)) * 100.00) + sorted) / 2.0;
	return (sorted);
}

short	act_logic(t_list **head_a, t_list **head_b, t_sort *s)
{
	// Maybe use fsl logic here?
	return (ok);
}

// Chooses most efficient node to push to a out of the ones connected
// Size + amount of act, lower = better
short	connect_pa(t_list **head_a, t_list **head_b, t_sort *s, t_act *a)
{
	return (ok);
}
