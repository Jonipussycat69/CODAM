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

// Pareses the starting-string and inputs it into a list
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
