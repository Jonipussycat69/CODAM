#include "push_swap.h"

int	bn(int one, int two)
{
	if (one > two)
		return (one);
	return (two);
}

int	sn(int one, int two)
{
	if (one < two)
		return (one);
	return (two);
}

int	rotate_amount_a(t_list **a, int b_num)
{
	t_list			*tmp;
	const t_list	*last_a = last_node(a);
	int				i;

	if (*a == NULL)
		return (0);
	i = 0;
	tmp = *a;
	while (tmp != NULL)
	{
		if (i == 0 && tmp->num > b_num && last_a->num < b_num)
			return (0);
		if (tmp == last_a && tmp->num < b_num && (*a)->num > b_num)
			return (i);
		if (i != 0 && tmp != last_a && tmp->num < b_num && tmp->next->num > b_num)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	act_arr_reset(t_sort *s)
{
	short	i;

	i = 0;
	while (i < 8)
	{
		s->act_arr[i] = 0;
		i++;
	}
	return ;
}

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
		prev_index = tmp->num;
		tmp = tmp->next;
		if (tmp->num < prev_index)
			return (err);
	}
	return (ok);
}
