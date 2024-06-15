#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_cmd_node
{
	char	*content;
	void	*next;
}	t_cmd_node;

typedef struct s_sig_argument
{
	t_cmd_node	**cmd_head; // can be used as single pointer, head stored in sig_argument node only
	char		**cmd_array;
	int			token;
	void		*next;
}	t_sig_argument;


#endif