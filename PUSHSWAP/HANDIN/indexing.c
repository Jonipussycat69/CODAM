#include "push_swap.h"

// Updates stack_i & list_i in both lists
void	update_variable_index(t_list **head_a, t_list **head_b)
{
	list_indexer(head_a);
	stack_indexer(head_a);
	list_indexer(head_b);
	stack_indexer(head_b);
	return ;
}

// Checks for doubles while assigning each value an corresponding index
short	indexer(t_list **head)
{
	t_list	*tmp;
	t_list	*tmptmp;
	int		i;
	short	double_check;

	tmp = *head;
	while (tmp != NULL)
	{
		double_check = 0;
		i = 0;
		tmptmp = *head;
		while (tmptmp != NULL)
		{
			if (tmp->value == tmptmp->value)
				double_check += 1;
			if (double_check > 1)
				return (err);
			if (tmp->value > tmptmp->value)
				i++;
			tmptmp = tmptmp->next;
		}
		tmp->i_value = i;
		tmp = tmp->next;
	}
	return (ok);
}

void	stack_indexer(t_list **head)
{
	t_list	*tmp;
	t_list	*tmptmp;
	int		i;

	if (!*head)
		return ;
	tmp = *head;
	while (tmp != NULL)
	{
		i = 0;
		tmptmp = *head;
		while (tmptmp != NULL)
		{
			if (tmp->value > tmptmp->value)
				i++;
			tmptmp = tmptmp->next;
		}
		tmp->stack_iv = i;
		tmp = tmp->next;
	}
	return ;
}

void	list_indexer(t_list **head)
{
	t_list	*tmp;
	int		i;

	if (!*head)
		return ;
	tmp = *head;
	i = 0;
	while (tmp != NULL)
	{
		tmp->list_index = i;
		tmp = tmp->next;
		i++;
	}
	return ;
}
