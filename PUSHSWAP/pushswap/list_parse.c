#include "push_swap.h"

int	get_index(t_list *node)
{
	if (!node)
		return (-1);
	return (node->i_value);
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
// Returns pointer on the index of the input starting from 0
t_list	*nth_node(t_list **head, int n)
{
	t_list	*tmp;
	
	if (!*head)
		return (NULL);
	tmp = *head;
	while (tmp->next != NULL && n-- > 0)
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
