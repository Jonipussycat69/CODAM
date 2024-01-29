#include "push_swap.h"

void	print_values(t_list **head)
{
	t_list	*tmp;

	tmp = *head;
	printf("Values:\n");
	while (tmp != NULL)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n\n");
	return ;
}

void	free_list(t_list **head)
{
	t_list	*tmp;
	t_list	*tmptmp;

	if (!*head)
		return ;
	tmp = *head;
	while (tmp != NULL)
	{
		tmp->next = tmptmp;
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

t_list	*new_node(int val, int ind)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = val;
	node->index = ind;
	node->next = NULL;
	return (node);
}

void	parser(char *input, t_list **head)
{
	t_list	*node;
	int		i;
	int		num;

	i = 0;
	while (input[i])
	{
		if (input[i] <= '9' && input[i] >= '0')
		{
			num = 0;
			while (input[i] <= '9' && input[i] >= '0')
			{
				num = num * 10 + (input[i] - '0');
				i++;
			}
			nodeadd_back(head, new_node(num, 0));
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

void	ft_pushswap(t_list **head)
{
	return ;
}

int	main(void)
{
	char	input[] = "12 23 34 45 11 67 32";
	t_list	*first;
	t_list	**head;

	first = NULL;
	head = &first;
	parser(input, head);
	indexer(head);
	print_values(head);
	ft_pushswap(head);
	free_list(head);
	return (0);
}
