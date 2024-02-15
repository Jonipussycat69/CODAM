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
		printf("%d ", tmp->i_value);
		tmp = tmp->next;
	}
	printf("\n\n");
	return ;
}

void	ft_pushswap(t_list **head_a, t_sort *s)
{
	t_list	*first;
	t_list	**head_b;
	const short	arr[11] = {sa, sb, pa, pb, ra, rb, rra, rrb, ss, rr, rrr};


	first = NULL;
	head_b = &first;
	if (!*head_a)
		return ;
	midsplit_algorithm(head_a, head_b, s, arr);// LEFTOFF
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
	s.total_inputsize = list_len(head);
	print_values(head);
	ft_pushswap(head, &s);
	free_list(head);
	return (0);
}
