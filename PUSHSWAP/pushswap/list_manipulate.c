#include "push_swap.h"

void	free_list(t_list **head)
{
	t_list	*tmp;
	t_list	*tmptmp;

	if (!*head)
		return ;
	tmp = *head;
	while (tmp != NULL)
	{
		tmptmp = tmp->next;
		free(tmp);
		tmp = tmptmp;
	}
	*head = NULL;
	return ;
}

void	nodeadd_back(t_list **head, t_list *node)
{
	t_list	*tmp;

	if (!*head)
	{
		*head = node;
		return ;
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
	return ;
}

void	nodeadd_front(t_list **head, t_list *node)
{
	if (!*head)
		*head = node;
	else
	{
		node->next = *head;
		*head = node;
	}
	return ;
}
