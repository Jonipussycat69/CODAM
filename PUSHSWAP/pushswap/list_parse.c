#include "push_swap.h"

int	get_i_value(t_list *node)
{
	if (!node)
		return (-1);
	return (node->i_value);
}

int	get_li(t_list *node)
{
	if (!node)
		return (-1);
	return (node->list_index);
}

int	get_value(t_list *node)
{
	if (!node)
		return (-1);
	return (node->value);
}

int	get_weight(t_list *node)
{
	if (!node)
		return (-1);
	return (node->weight);
}

int	get_mark(t_list *node)
{
	if (!node)
		return (-1);
	return (node->mark);
}

int	get_side(t_list *node)
{
	if (!node)
		return (-1);
	return (node->side);
}

int	list_len(t_list **head)
{
	t_list	*tmp;
	int		i;
	
	if (!*head)
		return (0);
	i = 0;
	tmp = *head;
	while (tmp != NULL && ++i)
		tmp = tmp->next;
	return (i);
}
