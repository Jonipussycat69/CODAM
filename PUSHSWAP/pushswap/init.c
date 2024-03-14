#include "push_swap.h"

void	assign_mark(t_list **head)
{
	t_list	*tmp;

	if (!*head)
		return ;
	tmp = *head;
	while (tmp != NULL)
	{
		tmp->mark = tmp->i_value - 1;
		tmp = tmp->next;
	}
	return ;
}
