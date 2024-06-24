#ifndef MINISH_PARAM_H
# define MINISH_PARAM_H
# include "libft/libft.h"
# include "minish_def.h"
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
# include <termios.h>

// Function parameters

// parsing.c

void	parsing_distributor(t_dad *d);

// utils_string.c

char	*strdup_index(char *str, size_t	start, size_t end);

// utils_sig_arg_list.c

bool	new_node_back_arglist
(
	t_cmd_node	**cmd_head,
	char		**cmd_arr,
	short		token,
	t_sig_arg	**head
);
t_sig_arg	*arglist_last_node(t_sig_arg **head);

// utils_cmd_list.c

bool		new_node_back_cmdlist(t_cmd_node **head, char *content);
t_cmd_node	**init_cmd_head(void);

// utils_exit.c

void	exit_clean(t_dad *d, int num, char *message);
void	exit_va_free(t_dad *d, int num, char *message, short amount, ...);

// utils_freeing.c

void	ifnotnull_free_setnull(void **ptr);

#endif
