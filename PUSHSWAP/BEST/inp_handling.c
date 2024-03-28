#include "push_swap.h"

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
		if (str[i] == '-' && ((i == 0 || str[i - 1] != ' ') || !ps_isdigit(str[i + 1])))
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
		return (argv[1]);
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

// Pareses the starting-string and inputs it into a list
short	parser(char *inp, t_list **head)
{
	int		i;
	t_parse	p;

	i = 0;
	if (!inp)
		return (err);
	while (inp[i])
	{
		p.min = 1;
		if (i > 0 && ps_isdigit(inp[i]) && inp[i - 1] == '-')
			p.min = -1;
		p.num = 0;
		while (ps_isdigit(inp[i]))
		{
			p.num = p.num * 10 + (inp[i] - '0');
			i++;
		}
		p.num *= p.min;
		if (i > 0 && ps_isdigit(inp[i - 1]) && (p.num < INT_MIN || \
		p.num > INT_MAX || node_back(head, new_node((int)p.num)) != ok))
			return (free_list(head), free(inp), err);
		i++;
	}
	free(inp);
	return (ok);
}
