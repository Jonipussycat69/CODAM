#include "push_swap.h"

// Checks the input string for value size and creates linked list with values
short	parser(char *input, t_list **head)
{
	int		i;
	long	num;
	short	multiplier;

	i = 0;
	while (input[i])
	{
		if (input[i] <= '9' && input[i] >= '0')
		{
			multiplier = 1;
			if (i > 0 && input[i - 1] == '-')
				multiplier = -1;
			num = 0;
			while (input[i] <= '9' && input[i] >= '0')
			{
				num = num * 10 + (input[i] - '0');
				i++;
			}
			if (num < INT_MIN || num > INT_MAX || \
			nodeadd_back(head, new_node((int)num * multiplier, 0)) != ok)
				return (free_list(head), err);
		}
		i++;
	}
	return (ok);
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
