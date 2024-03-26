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

// Returns 'ok' if stack is sorted perfectly ascending, 'err' if not
short	strict_check_asc(t_list **head)
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
		if (tmp->i_value != prev_index + 1)
			return (err);
	}
	return (ok);
}
