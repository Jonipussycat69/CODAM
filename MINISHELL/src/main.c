/*
MINISHELL:

Part list:
- History management
- Cmd management
- File/ dir management
- Sig management
*/

#include "../minishell.h"

short	sig = 0;

void	exit_error(t_dad *d, int num, char *message)
{
	//cleanup
	perror(message);
	exit(num);
}

void	exit_success(t_dad *d)
{
	//cleanup
	exit(EXIT_SUCCESS);
}

void	parse_line(t_dad *d, char *line)
{
	if (!ft_strncmp(line, "exit", 5))
	{
		free(line);
		exit_success(d);
	}
}

int	main(void)
{
	char	*line;
	t_dad	d;

	while (true)
	{
		line = readline(C_YELLOW "mini" C_RED " > " C_RESET);
		if (!line)
			exit_error(&d, errno, NULL);
		parse_line(&d, line);
		free(line);
	}
	return (0);
}
