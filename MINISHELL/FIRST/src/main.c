#include "../minishell.h"

int	the_loop(void)
{
	char	*line;
	int		i = 0;

	while (i++ < 10)
	{
		line = readline("minishell$ ");
		if (!line || !ft_strncmp(line, "exit", 5))
			return (free(line), 0);
		ft_printf("INP: %s\n", line);
		free(line);
	}
	return (1);
}

int	main(void)
{
	ft_printf("START\n");
	ft_printf("RET: %i\n", the_loop());
	ft_printf("END\n");
}