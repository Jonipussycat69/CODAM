#include "push_swap.h"

int	abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int	total_act(t_list *n)
{
	return (n->ra + n->rb + n->rra + n->rrb);
}

void	zero_node_act(t_list **head)
{
	t_list	*tmp;

	if (!head || !(*head))
		return ;
	tmp = *head;
	while (tmp != NULL)
	{
		tmp->ra = 0;
		tmp->rb = 0;
		tmp->rra = 0;
		tmp->rrb = 0;
		tmp = tmp->next;
	}
}