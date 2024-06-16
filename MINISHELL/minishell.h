#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
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

// Colors

# define C_RESET "\033[0m"
# define C_TEAL "\033[0;36m"
# define C_YELLOW "\033[0;33m"
# define C_RED "\033[31;1m"

// Enums

enum	e_function_return
{
	SUCCESS = 1,
	NEUTRAL = 0,
	ERROR = -1,
	MEM_ERR = -2,
	MAL_ERR = -3
};

// STRUCTS

// Cmd and arg structs

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

typedef struct s_father_of_all_structs
{
	t_sig_argument	sig_arg;
}	t_dad;

#endif
