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

int	rotate_amount_b(t_list **b, int a_num)
{
	t_list	*tmp;
	int		i;

	if (*b == NULL)
		return (0);
	i = 0;
	tmp = *b;
	while (tmp->num > a_num && tmp->next != NULL)
	{
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
