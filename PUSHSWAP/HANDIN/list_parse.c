#include "push_swap.h"

// Find the node with a stack_iv of 'n'
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

// Find the node with a list_index of 'n'
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

// Find the node with a i_value of 'n'
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
