/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inp_handling.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/06 13:26:38 by jdobos        #+#    #+#                 */
/*   Updated: 2024/06/11 16:05:30 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

short	char_check(char *str)
{
	int	i;

	if (!str)
		return (err);
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !ps_isdigit(str[i]) && str[i] != '-')
			return (err);
		if (str[i] == '-' && (!ps_isdigit(str[i + 1]) || \
		!(i == 0 || str[i - 1] == ' ')))
			return (err);
		i++;
	}
	return (ok);
}

char	*input_to_string(int argc, char **argv)
{
	char	*str;
	int		i;

	if (argc == 2)
	{
		if (char_check(argv[1]) != ok)
			return (NULL);
		return (ps_strdup(argv[1]));
	}
	i = 1;
	str = NULL;
	while (i < argc)
	{
		str = ps_strjoin(argv[i], str, 0, 0);
		if (!str)
			return (NULL);
		str = ps_strjoin(" ", str, 0, 0);
		if (!str)
			return (NULL);
		i++;
	}
	if (char_check(str) != ok)
		return (free(str), NULL);
	return (str);
}

static void	num_to_node(int len, long num, t_list **head, char *inpstr)
{
	if (len > 11 || num < INT_MIN || num > INT_MAX)
	{
		free(inpstr);
		free_list(head);
		wr_err("Error");
	}
	if (node_back(head, new_node((int)num)) != ok)
	{
		free(inpstr);
		free_list(head);
		wr_err("Error");
	}
}

// Pareses the starting-string and inputs it into a list
short	parser(char *inp, t_list **head)
{
	int		i;
	t_parse	p;

	if (!inp)
		return (err);
	i = 0;
	while (inp[i])
	{
		p.min = 1;
		if (i > 0 && ps_isdigit(inp[i]) && inp[i - 1] == '-')
			p.min = -1;
		p.num = 0;
		p.start = i;
		while (ps_isdigit(inp[i]))
		{
			p.num = p.num * 10 + (inp[i] - '0');
			i++;
		}
		p.num *= p.min;
		if (i > 0 && ps_isdigit(inp[i - 1]))
			num_to_node(i - p.start, p.num, head, inp);
		i++;
	}
	free(inp);
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
			if (tmp->num == tmptmp->num)
				double_check += 1;
			if (double_check > 1)
				return (free_list(head), err);
			else if (tmp->num > tmptmp->num)
				i++;
			tmptmp = tmptmp->next;
		}
		tmp->n_i = i;
		tmp = tmp->next;
	}
	return (ok);
}
