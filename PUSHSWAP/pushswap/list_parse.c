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

int	get_flag(t_list *node)
{
	if (!node)
		return (-1);
	return (node->flag);
}

t_list	*last_node(t_list **head)
{
	t_list	*tmp;
	
	if (!*head)
		return (NULL);
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int	list_len(t_list **head)
{
	t_list	*tmp;
	int		i;
	
	if (!*head)
		return (0);
	i = 0;
	tmp = *head;
	while (tmp->next != NULL && ++i)
		tmp = tmp->next;
	return (i);
}
