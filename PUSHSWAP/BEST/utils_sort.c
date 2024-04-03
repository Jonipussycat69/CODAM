#include "push_swap.h"

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

int	rotate_b(t_list **b, int num)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *b;
	while (tmp->num > num && tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	weigh(t_list **a, t_list **b, t_sort *s, t_list *node)
{
	const	r_a = s->index;
	const	rr_a = s->index - list_len(a);
	const	r_b = rotate_b(b, node->num);
	const	rr_b = r_b - list_len(b);
	
	// LEFTOFF
}
