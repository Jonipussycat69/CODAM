#include "push_swap.h"

short	char_check(char *str)
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

char	*input_to_string(int argc, char **argv, t_misc *m)
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
	m->str_to_free = str;
	return (str);
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
