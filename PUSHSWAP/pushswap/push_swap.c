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

static short	char_check(char *str)
{
	if (!str)
		return (err);
	while (*str)
	{
		if (*str != ' ' && ps_isdigit(*str) != ok)
			return (err);
		str++;
	}
	return (ok);
}

static char	*input_to_string(int argc, char **argv, t_sort *s)
{
	char	*str;
	int		i;

	if (argc == 2)
	{
		if (char_check(argv[1]) != ok)
			return (NULL);
		return (argv[1]);
	}
	i = 1;
	str = NULL;
	while (i < argc)
	{
		str = ps_strjoin(argv[i], str, 0, 0);// Well protected?
		str = ps_strjoin(" ", str, 0, 0);
		if (!str)
			return (NULL);
		i++;
	}
	if (char_check(str) != ok)
		return (free(str), NULL);
	s->str_to_free = str;
	return (str);
}

static short	ft_pushswap(t_list **head_a, t_sort *s)
{
	t_list	*first;
	t_list	**head_b;
	const short	arr[11] = {sa, sb, pa, pb, ra, rb, rra, rrb, ss, rr, rrr};

	first = NULL;
	head_b = &first;
	if (!*head_a)
		return (err);
	if (algo_swap_push(head_a, head_b, s, arr) == err)
		return (free_list(head_a), free_list(head_b), err);
	return (ok);
}

int	main(void)// TEST MAIN
{
	const char	input[] = "73 23 217 312 3173 -3 93";
	short	ret;
	t_list	*first;
	t_list	**head;
	t_sort	s;

	first = NULL;
	head = &first;
	s.str_to_free = NULL;
	// if (argc <= 1)
	// 	return (-1);
	if (parser((char *)input, head) != ok)
		return (wr_a("Error"), -1);
	if (s.str_to_free)
		free(s.str_to_free);
	if (indexer(head) != ok)
		return (wr_a("Error"), -1);
	assign_mark(head);
	s.total_inputsize = list_len(head);
	print_values(head);
	if (ft_pushswap(head, &s) != ok)
		return (wr_a("Error"), -1);
	free_list(head);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	short	ret;
// 	t_list	*first;
// 	t_list	**head;
// 	t_sort	s;

// 	first = NULL;
// 	head = &first;
// 	s.str_to_free = NULL;
// 	if (argc <= 1)
// 		return (-1);
// 	if (parser(input_to_string(argc, argv, &s), head) != ok)
// 		return (wr_a("Error"), -1);
// 	if (s.str_to_free)
// 		free(s.str_to_free);
// 	if (indexer(head) != ok)
// 		return (wr_a("Error"), -1);
// 	assign_mark(head);
// 	s.total_inputsize = list_len(head);
// 	print_values(head);
// 	if (ft_pushswap(head, &s) != ok)
// 		return (wr_a("Error"), -1);
// 	free_list(head);
// 	return (0);
// }
