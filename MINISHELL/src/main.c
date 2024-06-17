/*
MINISHELL:

Part list:
- History management
- Cmd management
- File/ dir management
- Sig management
*/

#include "../minish_param.h"

short	sig = 0;

// Frees main stings, linkedlists and exits.
void	exit_clean(t_dad *d, int num, char *message)
{
	//cleanup
	free(d->line);
	free(d->prev_line);
	rl_clear_history();
	errno = num;
	if (num != EXIT_SUCCESS)
		perror(message);
	exit(num);
}

// Initializes struct of all structs: t_dad.
void	init_dad(t_dad *d)
{
	d->prev_line = NULL;
	d->line = NULL;
}

bool	syntax_check(const char *line)
{
	size_t	i;
	t_uint	s_quote_count;
	t_uint	d_quote_count;

	i = 0;
	s_quote_count = 0;
	d_quote_count = 0;
	while (line[i])
	{
		if (line[i] == '\'')
			++s_quote_count;
		if (line[i] == '\"')
			++d_quote_count;
		++i;
	}
	if (s_quote_count % 2 != 0 || d_quote_count % 2 != 0)
		return (ERROR);
	return (NEUTRAL);
}

// Adds current line to history if:
// line_len > 0 && line != previous line.
// Lastly: strdups line to prev_line.
void	line_history_management(t_dad *d)
{
	const size_t	line_len = ft_strlen(d->line);

	if (line_len && \
	(!d->prev_line || ft_strncmp(d->line, d->prev_line, line_len + 1)))
	{
		add_history(d->line);
		free(d->prev_line);
		d->prev_line = ft_strdup(d->line);
		if (!d->prev_line)
			exit_clean(d, errno, NULL);
	}
}

void	line_parse(t_dad *d)
{
	if (!ft_strncmp(d->line, "exit", 5))
		exit_clean(d, EXIT_SUCCESS, NULL);
}

int	main(void)
{
	t_dad	d;

	init_dad(&d);
	while (true)
	{
		d.line = readline(C_YELLOW "mini" C_RED " > " C_RESET);
		if (!d.line)
			break ;
		if (!syntax_check(d.line))
		{
			line_history_management(&d);
			line_parse(&d);
		}
		else
			printf("syntax error\n");
		free(d.line);
	}
	free(d.prev_line);
	rl_clear_history();
	return (0);
}
