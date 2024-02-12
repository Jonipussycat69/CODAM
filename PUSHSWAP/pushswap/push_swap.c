#include "push_swap.h"

void	print_values(t_list **head)
{
	// THIS FUNCTION IS JUST FOR TETSTING!!
	t_list	*tmp;

	tmp = *head;
	printf("Values:\n");
	while (tmp != NULL)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n\n");
	tmp = *head;
	printf("Index:\n");
	while (tmp != NULL)
	{
		printf("%d ", tmp->index);
		tmp = tmp->next;
	}
	printf("\n\n");
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

void	ft_pushswap(t_list **head_a, t_sort *s)
{
	t_list	*first;
	t_list	**head_b;

	first = NULL;
	head_b = &first;
	if (!*head_a)
		return ;
	choose_action(head_a, head_b, s);// LEFTOFF
	return ;
}

int	main(void)
{
	char	input[] = "12 -23 34 45 11 67 32";
	t_list	*first;
	t_list	**head;
	t_sort	s;

	first = NULL;
	head = &first;
	parser(input, head);
	indexer(head);
	s.inputsize = list_len(head);
	print_values(head);
	ft_pushswap(head, &s);
	free_list(head);
	return (0);
}
