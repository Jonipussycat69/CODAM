#include "push_swap.h"

void	parser(char *input, t_list **head)
{
	int		i;
	int		num;
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
			if (nodeadd_back(head, new_node(num * multiplier, 0)) != ok)
				return (free_list(head));
		}
		i++;
	}
	return ;
}

void	indexer(t_list **head)
{
	t_list	*tmp;
	t_list	*tmptmp;
	int		i;

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
		tmp->index = i;
		tmp = tmp->next;
	}
	return ;
}

void	list_indexer(t_list **head)
{
	t_list	*tmp;
	int		i;

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
