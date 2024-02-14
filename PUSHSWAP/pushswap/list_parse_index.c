#include "push_swap.h"

t_list	*n_si_node(t_list **head, int n)
{
	t_list	*tmp;
	
	if (!*head)
		return (NULL);
	tmp = *head;
	while (tmp != NULL && tmp->stack_iv != n)
		tmp = tmp->next;
	return (tmp);
}

t_list	*n_li_node(t_list **head, int n)
{
	t_list	*tmp;
	
	if (!*head)
		return (NULL);
	tmp = *head;
	while (tmp != NULL && tmp->list_index != n)
		tmp = tmp->next;
	return (tmp);
}

t_list	*n_iv_node(t_list **head, int n)
{
	t_list	*tmp;
	
	if (!*head)
		return (NULL);
	tmp = *head;
	while (tmp != NULL && tmp->i_value != n)
		tmp = tmp->next;
	return (tmp);
}
